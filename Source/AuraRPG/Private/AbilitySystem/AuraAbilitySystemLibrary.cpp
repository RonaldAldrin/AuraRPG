// Copyrights Awie


#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "UI/HUD/AuraHUD.h"
#include "Player/AuraPlayerState.h"
#include "UI/WidgetController/AuraWidgetController.h"

#include "Kismet/GameplayStatics.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			AAuraPlayerState* AuraPlayerState = PC->GetPlayerState<AAuraPlayerState>();
			
			/*FWidgetControllerParams WidgetControllerParams;
			WidgetControllerParams.AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
			WidgetControllerParams.AttributeSet = AuraPlayerState->GetAttrabuteSet();
			WidgetControllerParams.PlayerController = PC;
			WidgetControllerParams.PlayerState = AuraPlayerState;*/

			UAbilitySystemComponent* ASC = AuraPlayerState->GetAbilitySystemComponent();
			UAttributeSet* AS = AuraPlayerState->GetAttrabuteSet();

			FWidgetControllerParams WidgetControllerParams(PC,AuraPlayerState,ASC,AS);

			return AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
			
			
		}
	}
	return nullptr;
}

UAttributeWidgetController* UAuraAbilitySystemLibrary::GetAttributeWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			AAuraPlayerState* AuraPlayerState = PC->GetPlayerState<AAuraPlayerState>();

			/*FWidgetControllerParams WidgetControllerParams;
			WidgetControllerParams.AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
			WidgetControllerParams.AttributeSet = AuraPlayerState->GetAttrabuteSet();
			WidgetControllerParams.PlayerController = PC;
			WidgetControllerParams.PlayerState = AuraPlayerState;*/

			UAbilitySystemComponent* ASC = AuraPlayerState->GetAbilitySystemComponent();
			UAttributeSet* AS = AuraPlayerState->GetAttrabuteSet();

			FWidgetControllerParams WidgetControllerParams(PC, AuraPlayerState, ASC, AS);

			return AuraHUD->GetAttributeWidgetController(WidgetControllerParams);


		}
	}
	return nullptr;
}
