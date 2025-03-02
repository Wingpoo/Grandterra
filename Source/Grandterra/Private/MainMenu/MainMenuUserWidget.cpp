// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/MainMenuUserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();


	if (BTN_SinglePlayer) BTN_SinglePlayer->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SinglePlayerButtonClicked); // Single Player
	if (BTN_Multiplayer) BTN_Multiplayer->OnClicked.AddDynamic(this, &UMainMenuUserWidget::MultiplayerButtonClicked); // Multiplayer
	if (BTN_Options) BTN_Options->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OptionsButtonClicked); // Options
	if (BTN_SubmitFeedback) BTN_SubmitFeedback->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SubmitFeedbackButtonClicked); // Feedback
	if (BTN_SubmitBug) BTN_SubmitBug->OnClicked.AddDynamic(this, &UMainMenuUserWidget::SubmitBugButtonClicked); // Bug
	if (BTN_Quit) BTN_Quit->OnClicked.AddDynamic(this, &UMainMenuUserWidget::QuitButtonClicked); // Quit
}

void UMainMenuUserWidget::SinglePlayerButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(1);
}

void UMainMenuUserWidget::MultiplayerButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(2);
}

void UMainMenuUserWidget::OptionsButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(3);
}

void UMainMenuUserWidget::SubmitFeedbackButtonClicked()
{
}

void UMainMenuUserWidget::SubmitBugButtonClicked()
{
}

void UMainMenuUserWidget::QuitButtonClicked()
{
	if (WS_Menu) WS_Menu->SetActiveWidgetIndex(4);
}
