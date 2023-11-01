// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;


UCLASS(Abstract) // Abstract specifier preventing this class to drag to the world/ level
class AURARPG_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	//if the interface function = 0/abstract you need to override the function to compile
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttrabuteSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo();

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect>GameplayEffectClass, float Level) const;

	void InitializeDefaultAttributes() const; // this call from Auracharacter;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

public:	


};
