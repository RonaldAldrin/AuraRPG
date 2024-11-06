// Copyright Awie

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURARPGV2_API AAuraEnemy : public AAuraCharacterBase
{
	GENERATED_BODY()
	

protected:

	virtual void BeginPlay() override;
};
