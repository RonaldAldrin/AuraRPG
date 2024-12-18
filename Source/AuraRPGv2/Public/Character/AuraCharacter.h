// Copyright Awie

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class AAuraPlayerState;

/**
 * 
 */
UCLASS()
class AURARPGV2_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:

	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/* begin Combat Interface */

	virtual int32 GetPlayerLevel() override;

	/* end Combat Interface */

	
protected:

	virtual void BeginPlay() override;

private:

	
	virtual void InitAbilityActorInfo() override;
	
};
