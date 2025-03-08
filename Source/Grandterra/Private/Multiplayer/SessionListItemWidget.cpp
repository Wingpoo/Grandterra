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
	UMultiplayerSubsystem* MPSS = GetGameInstance()->GetSubsystem<UMultiplayerSubsystem>();
	if (MPSS) MPSS->JoinSessionIndex(SessionResultIndex);
}

void USessionListItemWidget::SetupText(FText SessionName, FText HostName)
{
	if (TXT_HostName) TXT_HostName->SetText(HostName);
	if (TXT_SessionName) TXT_SessionName->SetText(SessionName);
}

void USessionListItemWidget::SetupSessionResult(USessionBrowserWidget* Parent, int Index)
{
	ParentWidget = Parent;

	SessionResultIndex = Index;
}
