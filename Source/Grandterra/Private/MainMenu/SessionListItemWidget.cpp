// Fill out your copyright notice in the Description page of Project Settings.


#include "Multiplayer/SessionListItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Multiplayer/SessionBrowserWidget.h"

void USessionListItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_Join) BTN_Join->OnClicked.AddDynamic(this, &USessionListItemWidget::JoinButtonClicked);

}

void USessionListItemWidget::JoinButtonClicked()
{
}

void USessionListItemWidget::Setup(USessionBrowserWidget* Parent, FOnlineSessionSearchResult Session)
{
	ParentWidget = Parent;
	SessionResult = Session;

	TXT_HostName->SetText(FText::FromString(Session.Session.OwningUserName));
	FString SessionName;
	Session.Session.SessionSettings.Get("SESSION_NAME", SessionName);
	TXT_SessionName->SetText(FText::FromString(SessionName));
}
