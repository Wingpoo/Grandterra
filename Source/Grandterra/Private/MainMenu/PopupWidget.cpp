// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/PopupWidget.h"
#include "Components/Button.h"
#include "MainMenu/MainMenuUserWidget.h"

void UPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_GoBack) BTN_GoBack->OnClicked.AddDynamic(this, &UPopupWidget::GoBackButtonClicked);
	if (BTN_Continue) BTN_Continue->OnClicked.AddDynamic(this, &UPopupWidget::ContinueButtonClicked);

	ParentWidget = GetTypedOuter<UMainMenuUserWidget>();
}

void UPopupWidget::GoBackButtonClicked()
{
	if(ParentWidget) ParentWidget->GoBackButtonClicked();
}

void UPopupWidget::ContinueButtonClicked()
{
	if (ParentWidget) ParentWidget->GoBackButtonClicked();
}