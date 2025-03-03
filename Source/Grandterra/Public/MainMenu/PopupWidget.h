// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopupWidget.generated.h"

/**
 * 
 */
class UMainMenuUserWidget;
class UButton;

UCLASS()
class GRANDTERRA_API UPopupWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_GoBack;


	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Continue;

	UFUNCTION()
	virtual void GoBackButtonClicked();

	UFUNCTION()
	virtual void ContinueButtonClicked();

	UPROPERTY()
	UMainMenuUserWidget* ParentWidget;
};
