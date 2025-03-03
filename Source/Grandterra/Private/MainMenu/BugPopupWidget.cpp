// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/BugPopupWidget.h"
#include "HAL/PlatformProcess.h"

void UBugPopupWidget::ContinueButtonClicked()
{
	Super::ContinueButtonClicked();
	FPlatformProcess::LaunchURL(TEXT("https://forms.gle/vnNYmhdbK5skHrCWA"), nullptr, nullptr);
}
