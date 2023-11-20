// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"


class UWidgetComponent;
class UTimelineComponent;
/**
 * 
 */




UCLASS(BlueprintType)
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

	//** Begin CombatInterface */
	virtual int32 GetPlayerLevel() override;
	//** End CombatInterface */

	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	virtual void Die() override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintReadOnly,Category = "Combat")
	bool bHitReacting = false;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Combat")
	float BaseWalkSpeed = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float LifeSpan = 5.f;

protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

<<<<<<< HEAD
	virtual void InitializeDefaultAttributes()  const override;



=======
>>>>>>> parent of ef2f4cd (Added RPG Chracter Classes)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UWidgetComponent> HealthBarWidget;




	
};
