// Copyright Awie

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS(Abstract)
class AURARPGV2_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AAuraCharacterBase();

	//===========
	// GETTER
	//===========
	// this ASC and AS is for enemy characters. the player character is in player state
	// the GetAbilitySystemComponent() is in IAbilitSystemInterface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// this GetAttributeSet() create manually
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo();

	void InitializePrimaryAttributes() const;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

public:	

	

};
