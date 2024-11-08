// Copyright Awie


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AuraRPGv2/AuraRPGv2.h"

#include "DrawDebugHelpers.h"

AAuraEnemy::AAuraEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	//Minimal is for multiplayer game only for AI-Controlled
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

}

void AAuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsHighlight)
	{
		//DrawDebugSphere(GetWorld(), GetActorLocation(), 60, 10, FColor::Red, false, -1, 0.f);
	}

}

void AAuraEnemy::HighlightActor()
{
	bIsHighlight = true;
	
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);

	
}

void AAuraEnemy::UnHighlightActor()
{
	bIsHighlight = false;

	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	
}
