// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExtraMenusWidget.generated.h"

/**
 * 
 */

class UButton;
class UMainMenuUserWidget;

UCLASS()
class GRANDTERRA_API UExtraMenusWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY()
	UMainMenuUserWidget* ParentWidget;

public:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Cancel;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Apply;

	UFUNCTION()
	void CancelButtonClicked();

	UFUNCTION()
	void ApplyButtonClicked();
};
