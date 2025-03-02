// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GRANDTERRA_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UMainMenuUserWidget> BP_MainMenu;

private:
	UMainMenuUserWidget* MainMenu;
};
