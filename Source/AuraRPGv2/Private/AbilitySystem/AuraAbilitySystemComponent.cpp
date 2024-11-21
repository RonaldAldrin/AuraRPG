// Copyright Awie


#include "AbilitySystem/AuraAbilitySystemComponent.h"

// this calls in Auracharacter and AuraEnemy
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	//use AddUObject when the delegate is not dynamic. Also when using delegate make sure the function has the same input variables the need
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, 
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	

	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);

}
