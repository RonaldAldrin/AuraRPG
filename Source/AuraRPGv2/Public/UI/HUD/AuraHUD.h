// Copyright Awie

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"


class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class AURARPGV2_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:


	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;


protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	
};
