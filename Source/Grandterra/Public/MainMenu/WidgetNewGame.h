// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetNewGame.generated.h"

/**
 * 
 */

class UButton;
class UEditableTextBox;
class UMainMenuUserWidget;


UCLASS()
class GRANDTERRA_API UWidgetNewGame : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY()
	UMainMenuUserWidget* ParentWidget;

	class UMultiplayerSubsystem* MultiplayerSubsystem;

	void BindButtons();

	FString CheckSessionName();

public:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Cancel;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Accept;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* ETB_NewGameName;

	UFUNCTION()
	void CancelButtonClicked();

	UFUNCTION()
	void SPAcceptButtonClicked();

	UFUNCTION()
	void MPAcceptButtonClicked();

	UFUNCTION()
	void NewGameNameChanged(const FText& Text);

};
