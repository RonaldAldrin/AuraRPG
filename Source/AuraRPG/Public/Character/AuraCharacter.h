// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURARPG_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	
public:

	AAuraCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:

	virtual void BeginPlay() override;

private:

	void InitAbilityActorInfo();


public:

};
