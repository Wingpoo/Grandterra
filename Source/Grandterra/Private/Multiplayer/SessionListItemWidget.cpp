// Fill out your copyright notice in the Description page of Project Settings.


#include "Multiplayer/SessionListItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Multiplayer/SessionBrowserWidget.h"
#include "Multiplayer/MultiplayerSubsystem.h"


void USessionListItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_Join) BTN_Join->OnClicked.AddDynamic(this, &USessionListItemWidget::JoinButtonClicked);

}

void USessionListItemWidget::JoinButtonClicked()
{
	if (!SessionResult.IsValid()) GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, "Session Result is Invalid");

	UMultiplayerSubsystem* MPSS = GetGameInstance()->GetSubsystem<UMultiplayerSubsystem>();
	if (MPSS) MPSS->JoinSession(SessionResult);
}

void USessionListItemWidget::SetupText()
{
	if (TXT_HostName) TXT_HostName->SetText(HostName);
	if (TXT_SessionName) TXT_SessionName->SetText(FText::FromString(SessionName));
}

void USessionListItemWidget::SetupSessionResult(USessionBrowserWidget* Parent, FOnlineSessionSearchResult Session)
{
	ParentWidget = Parent;

	SessionResult = Session;


	SessionResult.Session.SessionSettings.Get("SESSION_NAME", SessionName);
	HostName = FText::FromString(SessionResult.Session.OwningUserName);
}
