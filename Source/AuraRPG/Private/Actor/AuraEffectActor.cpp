// Copyrights Awie


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"




AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));



}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();


}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	/*if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target))
	{
		ASCInterface->GetAbilitySystemComponent();
		//this method is same as the UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target) 
		//UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target) this is much better than casting and get abilitysystem component
	}*/

	
	if (TargetActor->ActorHasTag(FName("Enemy")) && !bApplyEffectsToEnemies) return;

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (TargetASC == nullptr) return;

	check(GameplayEffectClass);

	// this TargetASC->MakeEffectContext() is need for MakeOutgoingSpec
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	// this will get the duration policy if it is infinite/instant/duration
	const bool bIsInfite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}

	if (!bIsInfite)
	{
		Destroy();
	}
	
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	if (TargetActor->ActorHasTag(FName("Enemy")) && !bApplyEffectsToEnemies) return;

	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}

}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (TargetActor->ActorHasTag(FName("Enemy")) && !bApplyEffectsToEnemies) return;

	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;

		// this array will add the handlepair.key and remove this in new loop
		TArray<FActiveGameplayEffectHandle> HandlesToRemove;

		for (TPair<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles)
		{
			if (TargetASC == HandlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
				HandlesToRemove.Add(HandlePair.Key);
			}
		}
		for (FActiveGameplayEffectHandle& Handle : HandlesToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
		
	}

}

/**
void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a Gameplay Effect. For now, Using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));

		// const_cast this method is to remove/castaway the const. this is bad programming practice
		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);

		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);

		Destroy();
	}
}
**/




