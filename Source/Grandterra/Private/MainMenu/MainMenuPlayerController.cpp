// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/MainMenuPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu/MainMenuUserWidget.h"

void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(true);
	SetInputMode(FInputModeUIOnly());

	if (BP_MainMenu)
	{
		MainMenu = CreateWidget<UMainMenuUserWidget>(this, BP_MainMenu);

		if (MainMenu)
		{
			MainMenu->AddToViewport();
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "Menu Widget not found");
	}
}
