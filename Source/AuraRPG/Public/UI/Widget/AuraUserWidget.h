// Copyrights Awie

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURARPG_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWIdgetController); // call from AuraHUD InitOverlay and WBP_Overlay

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;



protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();


};
