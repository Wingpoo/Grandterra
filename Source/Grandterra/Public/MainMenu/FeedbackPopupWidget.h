// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenu/PopupWidget.h"
#include "FeedbackPopupWidget.generated.h"

/**
 * 
 */
UCLASS()
class GRANDTERRA_API UFeedbackPopupWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
	void ContinueButtonClicked() override;
};
