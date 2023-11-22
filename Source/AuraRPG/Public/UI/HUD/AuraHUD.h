// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;
class UAbilitySystemComponent;
class UAttributeSet;
class UAttributeWidgetController;
/**
 * 
 */
UCLASS()
class AURARPG_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:



	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCPArams);

	// this will Initialized in AAurCharacter
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UAttributeWidgetController* GetAttributeWidgetController(const FWidgetControllerParams& WCPArams);

	

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;


	UPROPERTY()
	TObjectPtr<UAttributeWidgetController> AttributeWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeWidgetController> AttributeWidgetControllerClass;
	
};
