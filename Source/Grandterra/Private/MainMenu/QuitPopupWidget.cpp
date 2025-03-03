// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/QuitPopupWidget.h"
#include "Kismet/KismetSystemLibrary.h"

void UQuitPopupWidget::ContinueButtonClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, "Attempting To Quit.");
	UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Quit, true);
}
