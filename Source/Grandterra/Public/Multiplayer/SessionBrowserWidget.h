// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "SessionBrowserWidget.generated.h"

/**
 * 
 */

class UButton;
class UEditableTextBox;
class UListView;
class UMultiplayerSubsystem;

UCLASS()
class GRANDTERRA_API USessionBrowserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UMultiplayerSubsystem* MPSS;

public:
	void NativeConstruct() override;


	void CreateList(TArray<FOnlineSessionSearchResult> Results);

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Search;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* ETB_SessionName;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* ETB_HostName;

	UPROPERTY(meta = (BindWIdget))
	UListView* LIST_SessionList;

	UFUNCTION()
	void SearchButtonClicked();

	TArray<FOnlineSessionSearchResult> SessionResults;
};
