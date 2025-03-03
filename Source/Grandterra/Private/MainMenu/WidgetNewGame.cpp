// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/WidgetNewGame.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "MainMenu/MainMenuUserWidget.h"

void UWidgetNewGame::NativeConstruct()
{
	Super::NativeConstruct();

	if (Type == 1)
	{
		if (BTN_Accept) BTN_Accept->OnClicked.AddDynamic(this, &UWidgetNewGame::SPAcceptButtonClicked);
	}
	else if (Type == 2)
	{
		if (BTN_Accept) BTN_Accept->OnClicked.AddDynamic(this, &UWidgetNewGame::MPAcceptButtonClicked);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "Set Type to 1 for SP, 2 for MP");
	}

	if (BTN_Cancel) BTN_Cancel->OnClicked.AddDynamic(this, &UWidgetNewGame::CancelButtonClicked);

	ParentWidget = GetTypedOuter<UMainMenuUserWidget>();

}

void UWidgetNewGame::CancelButtonClicked()
{
	if (ParentWidget) ParentWidget->CloseExtras();
}

void UWidgetNewGame::SPAcceptButtonClicked()
{

}

void UWidgetNewGame::MPAcceptButtonClicked()
{
}
