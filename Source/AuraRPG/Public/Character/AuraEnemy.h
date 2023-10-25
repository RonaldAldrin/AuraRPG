// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURARPG_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	
	AAuraEnemy();

	virtual void Tick(float DeltaTime) override;
	//** Begin EnemyInterface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//** End EnemyInterface */

protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
	
};
