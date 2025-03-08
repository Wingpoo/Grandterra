// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "SessionListItemWidget.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;
class USessionBrowserWidget;

UCLASS()
class GRANDTERRA_API USessionListItemWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	USessionBrowserWidget* ParentWidget;


public:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Join;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TXT_SessionName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TXT_HostName;

	UFUNCTION()
	void JoinButtonClicked();

	UFUNCTION()
	void SetupText();

	void SetupSessionResult(USessionBrowserWidget* Parent, FOnlineSessionSearchResult Session);

	FOnlineSessionSearchResult SessionResult;

	FString SessionName;
	FText HostName;
};
