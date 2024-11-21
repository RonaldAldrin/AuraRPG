// Copyright Awie

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURARPGV2_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()


	

public:

	AAuraEnemy();

	virtual void Tick(float DeltaTime) override;


	/* begin Enemy Interface */

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	/* end Enemy Interface */

protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;


};
