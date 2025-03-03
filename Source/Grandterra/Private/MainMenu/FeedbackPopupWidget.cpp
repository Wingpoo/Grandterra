// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/FeedbackPopupWidget.h"
#include "HAL/PlatformProcess.h"

void UFeedbackPopupWidget::ContinueButtonClicked()
{
	Super::ContinueButtonClicked();
	FPlatformProcess::LaunchURL(TEXT("https://forms.gle/KaKaSyH95pj6zjHp7"), nullptr, nullptr);
}
