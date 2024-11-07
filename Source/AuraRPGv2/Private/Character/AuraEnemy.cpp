// Copyright Awie


#include "Character/AuraEnemy.h"
#include "DrawDebugHelpers.h"
#include "AuraRPGv2/AuraRPGv2.h"


AAuraEnemy::AAuraEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

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
