// Copyrights Awie


#include "Character/AuraCharacter.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "UI/HUD/AuraHUD.h"
#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



void AAuraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// init ability actor info for the Server
	InitAbilityActorInfo();



}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// init ability actor info for the Client
	InitAbilityActorInfo();
}

int32 AAuraCharacter::GetPlayerLevel()
{
	const AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);

	return AuraPlayerState->GetPlayerLevel();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this); // InitAbilityActorInfo set the owner of the abilitysystem and the avatar/character that will use the abilitysystem
	Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttrabuteSet();

	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		//checkf(AuraHUD, TEXT("AuraHUD is invalid in multiplayer game do an if statement not assert check"));
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			//AuraHUD->InitAttribute(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	
	}
	InitializeDefaultAttributes();
}



