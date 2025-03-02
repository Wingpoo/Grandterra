// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/MainMenuGameMode.h"
#include "MainMenu/MainMenuPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AMainMenuGameMode::AMainMenuGameMode()
{
	static ConstructorHelpers::FClassFinder<AMainMenuPlayerController> PlayerControllerBPClass(TEXT("/Game/MainMenu/BP_MainMenuPlayerController"));
	if (PlayerControllerBPClass.Succeeded())
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, "Unable to find PlayerControllerBPClass");
		PlayerControllerClass = AMainMenuPlayerController::StaticClass();
	}

	DefaultPawnClass = NULL;

}
