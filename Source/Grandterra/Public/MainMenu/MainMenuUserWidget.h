// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuUserWidget.generated.h"

/**
 * 
 */

class UButton;
class UWidgetSwitcher;



UCLASS()
class GRANDTERRA_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	/** WIDGET SWITCHERS */
	
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* WS_Menu;

public:
	/** MAIN MENU BUTTONS */

	UPROPERTY (meta = (BindWidget))
	UButton* BTN_SinglePlayer;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Multiplayer;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Options;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_SubmitFeedback;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_SubmitBug;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Quit;

public:
	/** Main Menu Function calls */
	
	UFUNCTION()
	void SinglePlayerButtonClicked();

	UFUNCTION()
	void MultiplayerButtonClicked();

	UFUNCTION()
	void OptionsButtonClicked();

	UFUNCTION()
	void SubmitFeedbackButtonClicked();

	UFUNCTION()
	void SubmitBugButtonClicked();

	UFUNCTION()
	void QuitButtonClicked();

public:
	/** Single Player Buttons*/

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_SP_New;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_SP_Continue;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_SP_Load;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_SP_GoBack;

public:
	/** Multiplayer Buttons*/

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_MP_New;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_MP_Continue;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_MP_Load;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_MP_Join;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_MP_GoBack;

public:
	/** Options Buttons*/

public:
	/** Quit Buttons*/
};
