// Fill out your copyright notice in the Description page of Project Settings.


#include "Multiplayer/MultiplayerSubsystem.h"

UMultiplayerSubsystem::UMultiplayerSubsystem()
{
}

void UMultiplayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();

		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UMultiplayerSubsystem::OnCreateSessionCompleteCallback);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UMultiplayerSubsystem::DestroySessionCompleteCallback);
		}
	}

}

void UMultiplayerSubsystem::Deinitialize()
{
}

void UMultiplayerSubsystem::CreateSession(FString SessionName)
{
	if (!SessionInterface.IsValid()) return;
	
	FNamedOnlineSession* ExistingSession = SessionInterface->GetNamedSession(*SessionName);
	if (ExistingSession)
	{
		SessionInterface->DestroySession(*SessionName);
		return;
	}
	ExistingSession = SessionInterface->GetNamedSession(NAME_GameSession);
	if (ExistingSession)
	{
		SessionInterface->DestroySession(NAME_GameSession);
		return;
	}
	
	if (bIsCreatingSession || bIsSearchingSessions) { GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Currently Making or Searching for Sessions"); return; }
	bIsCreatingSession = true;

	FOnlineSessionSettings SessionSettings;

	SessionSettings.NumPublicConnections = 2;
	SessionSettings.bAllowJoinInProgress = true;
	SessionSettings.bAllowInvites = true;
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUseLobbiesIfAvailable = true;
	SessionSettings.bIsDedicated = false;

	if (IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
	{
		SessionSettings.bIsLANMatch = true;
		SessionSettings.bUsesPresence = true;
		if (!SessionInterface->CreateSession(0, NAME_GameSession, SessionSettings))
		{
			bIsCreatingSession = false;
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Failed to create session.");
			return;
		}
	}
	else
	{
		SessionSettings.bIsLANMatch = false;
		SessionSettings.bUsesPresence = true;
		if (!SessionInterface->CreateSession(0, *SessionName, SessionSettings))
		{
			bIsCreatingSession = false;
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Failed to create session.");
			return;
		}
	}


	
}

void UMultiplayerSubsystem::DestroySessionCompleteCallback(FName SessionName, bool Success)
{
	if (Success)
	{
		CreateSession(SessionName.ToString());
	}
}

void UMultiplayerSubsystem::FindSessions()
{

}

void UMultiplayerSubsystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{
}

void UMultiplayerSubsystem::OnCreateSessionCompleteCallback(FName SessionName, bool bWasSuccessful)
{
	OnCreateSessionComplete.Broadcast(bWasSuccessful);

	bIsCreatingSession = false;

	if (bWasSuccessful)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{

			FString CurrentSessionName = SessionInterface->GetNamedSession(SessionName)->SessionName.ToString();
			FString CurrentSessionHost = SessionInterface->GetNamedSession(SessionName)->OwningUserName;
			
			FString ShortenedCurrentSessionHost = CurrentSessionHost.Len() > 8 ? CurrentSessionHost.Left(4) + CurrentSessionHost.Right(8) : CurrentSessionHost;

			UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *ShortenedCurrentSessionHost, *CurrentSessionName);

			PC->SetShowMouseCursor(false);
			PC->SetInputMode(FInputModeGameOnly());
			FString MapName = "/Game/Maps/Main";
			GetWorld()->ServerTravel(MapName + "?listen");
		}
	}
}

void UMultiplayerSubsystem::OnFindSessionsCompleteCallback(bool bWasSuccessful)
{
}

void UMultiplayerSubsystem::OnJoinSessionCompleteCallback(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}
