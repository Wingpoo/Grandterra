// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenu/PopupWidget.h"
#include "QuitPopupWidget.generated.h"

/**
 * 
 */
UCLASS()
class GRANDTERRA_API UQuitPopupWidget : public UPopupWidget
{
	GENERATED_BODY()
	
	void ContinueButtonClicked() override;
};
