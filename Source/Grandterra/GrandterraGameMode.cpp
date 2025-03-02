// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrandterraGameMode.h"
#include "GrandterraCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGrandterraGameMode::AGrandterraGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
