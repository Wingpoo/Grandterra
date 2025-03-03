// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/ExtraMenusWidget.h"
#include "Components/Button.h"
#include "MainMenu/MainMenuUserWidget.h"

void UExtraMenusWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_Cancel) BTN_Cancel->OnClicked.AddDynamic(this, &UExtraMenusWidget::CancelButtonClicked);
	if (BTN_Apply) BTN_Apply->OnClicked.AddDynamic(this, &UExtraMenusWidget::ApplyButtonClicked);
	ParentWidget = GetTypedOuter<UMainMenuUserWidget>();

}

void UExtraMenusWidget::CancelButtonClicked()
{
	if (ParentWidget) ParentWidget->CloseExtras();
}

void UExtraMenusWidget::ApplyButtonClicked()
{
}
