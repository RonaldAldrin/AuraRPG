// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AuraPlayerState.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;
class AAuraCharacter;

UCLASS()
class AURARPG_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:

	AAuraPlayerState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttrabuteSet() const { return AttributeSet; }


	FORCEINLINE int32 GetPlayerLevel() const { return Level; }

protected:

	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AAuraCharacter> AuraCharacter;

private:

	UPROPERTY(ReplicatedUsing = OnRep_Level, VisibleAnywhere);
	int32 Level = 1;


	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
