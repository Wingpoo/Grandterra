// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/WidgetNewGame.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "MainMenu/MainMenuUserWidget.h"

void UWidgetNewGame::NativeConstruct()
{
	Super::NativeConstruct();

	FString ThisThingsName;
	GetName(ThisThingsName);

	if (ThisThingsName == "4_SPNewGame")
	{
		if (BTN_Accept) BTN_Accept->OnClicked.AddDynamic(this, &UWidgetNewGame::SPAcceptButtonClicked);
	}
	else if (ThisThingsName == "5_MPNewGame")
	{
		if (BTN_Accept) BTN_Accept->OnClicked.AddDynamic(this, &UWidgetNewGame::MPAcceptButtonClicked);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "The Button you just clicked should be in a widget placed in the widget switcher");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "And should be named 4_SPNewGame for single player and 5_MPNewGame for multiplayer");
	}

	if (ETB_NewGameName) ETB_NewGameName->OnTextChanged.AddDynamic(this, &UWidgetNewGame::NewGameNameChanged);

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

void UWidgetNewGame::NewGameNameChanged(const FText& Text)
{

	FString NewText = Text.ToString();
	if (NewText.IsEmpty()) return;


	//Checks if Text is too long
	if (NewText.Len() > 16)
	{
		NewText = NewText.Left(16);
	}

	//Checks if last character is alpha numeric
	TCHAR LastChar = NewText[NewText.Len() - 1];

	if (!FChar::IsAlnum(LastChar))
	{
		NewText = NewText.LeftChop(1);
	}

	//Only updates if the New Text is different
	if (NewText == Text.ToString()) return;

	ETB_NewGameName->SetText(FText::FromString(NewText));
}
