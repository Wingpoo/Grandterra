// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "SessionListItemWidget.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;
class USessionBrowserWidget;

UCLASS()
class GRANDTERRA_API USessionListItemWidget : public UUserWidget
{
	GENERATED_BODY()

	USessionBrowserWidget* ParentWidget;

	FOnlineSessionSearchResult SessionResult;
	
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

	void Setup(USessionBrowserWidget* Parent, FOnlineSessionSearchResult Session);

};
