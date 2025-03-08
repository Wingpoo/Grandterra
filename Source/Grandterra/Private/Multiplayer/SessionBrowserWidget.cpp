// Fill out your copyright notice in the Description page of Project Settings.


#include "Multiplayer/SessionBrowserWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/ListView.h"
#include "Multiplayer/MultiplayerSubsystem.h"
#include "Multiplayer/SessionListItemWidget.h"


void USessionBrowserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_Search) BTN_Search->OnClicked.AddDynamic(this, &USessionBrowserWidget::SearchButtonClicked);

	MPSS = GetGameInstance()->GetSubsystem<UMultiplayerSubsystem>();

	MPSS->OnFindSessionComplete.AddUObject(this, &USessionBrowserWidget::CreateList);
}


void USessionBrowserWidget::CreateList(TArray<FOnlineSessionSearchResult> Results)
{

	if (!LIST_SessionList) return;

	SessionResults = Results;

	for (FOnlineSessionSearchResult Result : SessionResults)
	{
		USessionListItemWidget* NewItem = CreateWidget<USessionListItemWidget>(this, USessionListItemWidget::StaticClass());
		if (NewItem)
		{
			LIST_SessionList->AddItem(NewItem);
			NewItem->SetupSessionResult(this, Result);
			NewItem->SetupText();
		}
	}
}

void USessionBrowserWidget::SearchButtonClicked()
{
	if (ETB_SessionName)
	{
		FString SessionName = ETB_SessionName->GetText().ToString();

		if (SessionName.IsEmpty()) return;

		if (MPSS) MPSS->FindSessions(SessionName);
	}
}
