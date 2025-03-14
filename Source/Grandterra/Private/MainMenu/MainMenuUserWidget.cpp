// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/MainMenuUserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"


void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_SinglePlayer) BTN_SinglePlayer->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SinglePlayerButtonClicked); // Single Player
	if (BTN_Multiplayer) BTN_Multiplayer->OnClicked.AddDynamic(this, &UMainMenuUserWidget::MultiplayerButtonClicked); // Multiplayer
	if (BTN_Options) BTN_Options->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OptionsButtonClicked); // Options
	if (BTN_SubmitFeedback) BTN_SubmitFeedback->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SubmitFeedbackButtonClicked); // Feedback
	if (BTN_SubmitBug) BTN_SubmitBug->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SubmitBugButtonClicked); // Bug
	if (BTN_Quit) BTN_Quit->OnClicked.AddDynamic(this, &UMainMenuUserWidget::QuitButtonClicked); // Quit

	//all go back buttons
	if (BTN_SP_GoBack) BTN_SP_GoBack->OnClicked.AddDynamic(this, &UMainMenuUserWidget::GoBackButtonClicked);
	if (BTN_MP_GoBack) BTN_MP_GoBack->OnClicked.AddDynamic(this, &UMainMenuUserWidget::GoBackButtonClicked);
	if (BTN_Options_GoBack) BTN_Options_GoBack->OnClicked.AddDynamic(this, &UMainMenuUserWidget::GoBackButtonClicked);

	//Single Player buttons
	if (BTN_SP_New) BTN_SP_New->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SinglePlayerNewButtonClicked);
	if (BTN_SP_Continue) BTN_SP_Continue->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SinglePlayerContinueButtonClicked);
	if (BTN_SP_Load) BTN_SP_Load->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SinglePlayerLoadButtonClicked);

	//Multiplayer buttons
	if (BTN_MP_New) BTN_MP_New->OnClicked.AddDynamic(this, &UMainMenuUserWidget::MultiplayerNewButtonClicked);
	if (BTN_MP_Continue) BTN_MP_Continue->OnClicked.AddDynamic(this, &UMainMenuUserWidget::MultiplayerContinueButtonClicked);
	if (BTN_MP_Load) BTN_MP_Load->OnClicked.AddDynamic(this, &UMainMenuUserWidget::MultiplayerLoadButtonClicked);
	if (BTN_MP_Join) BTN_MP_Join->OnClicked.AddDynamic(this, &UMainMenuUserWidget::MultiplayerJoinButtonClicked);

	//Options Buttons
	if (BTN_Options_Keybindings) BTN_Options_Keybindings->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OptionsKeybindingsButtonClicked);
	if (BTN_Options_GameSettings) BTN_Options_GameSettings->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OptionsGameSettingsButtonClicked);
	if (BTN_Options_SystemSettings) BTN_Options_SystemSettings->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OptionsSystemSettingsButtonClicked);

}

void UMainMenuUserWidget::SinglePlayerButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(1);
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(0);
}

void UMainMenuUserWidget::MultiplayerButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(2);
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(0);
}

void UMainMenuUserWidget::OptionsButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(3);
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(0);
}

void UMainMenuUserWidget::SubmitFeedbackButtonClicked()
{
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(2);
}

void UMainMenuUserWidget::SubmitBugButtonClicked()
{
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(3);
}

void UMainMenuUserWidget::QuitButtonClicked()
{
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(1);
}

void UMainMenuUserWidget::GoBackButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(0);
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(0);
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(0);
}

void UMainMenuUserWidget::SinglePlayerNewButtonClicked()
{
	if (WS_ExtraMenus) WS_Popups->SetActiveWidgetIndex(4);
}

void UMainMenuUserWidget::SinglePlayerContinueButtonClicked()
{
}

void UMainMenuUserWidget::SinglePlayerLoadButtonClicked()
{
}

void UMainMenuUserWidget::MultiplayerNewButtonClicked()
{
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(5);
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(0);

}

void UMainMenuUserWidget::MultiplayerContinueButtonClicked()
{
}

void UMainMenuUserWidget::MultiplayerLoadButtonClicked()
{
}

void UMainMenuUserWidget::MultiplayerJoinButtonClicked()
{
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(4);
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(0);
}

void UMainMenuUserWidget::OptionsKeybindingsButtonClicked()
{
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(1);
}

void UMainMenuUserWidget::OptionsGameSettingsButtonClicked()
{
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(2);
}

void UMainMenuUserWidget::OptionsSystemSettingsButtonClicked()
{
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(3);
}

void UMainMenuUserWidget::CloseExtras()
{
	if (WS_ExtraMenus) WS_ExtraMenus->SetActiveWidgetIndex(0);
	if (WS_Popups) WS_Popups->SetActiveWidgetIndex(0);
}
