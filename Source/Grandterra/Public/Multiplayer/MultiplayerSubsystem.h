// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"

#include "MultiplayerSubsystem.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FCreateSessionDelegate, bool);
DECLARE_MULTICAST_DELEGATE_OneParam(FFindSessionDelegate, TArray<FOnlineSessionSearchResult>);
DECLARE_MULTICAST_DELEGATE_OneParam(FJoinSessionDelegate, bool);

UCLASS()
class GRANDTERRA_API UMultiplayerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	bool bIsCreatingSession = false;
	bool bIsSearchingSessions = false;

	FString SessionNameToDestroy = "";
	bool bIsDestroyingSession = false;

public:
	UMultiplayerSubsystem();

	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	void CreateSession(FString SessionName);
	void FindSessions(FString SessionName);
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);

	FCreateSessionDelegate OnCreateSessionComplete;
	FFindSessionDelegate OnFindSessionComplete;
	FJoinSessionDelegate OnJoinSessionComplete;

protected:
	void OnCreateSessionCompleteCallback(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsCompleteCallback(bool bWasSuccessful);
	void OnJoinSessionCompleteCallback(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void DestroySessionCompleteCallback(FName SessionName, bool Success);

private:
	IOnlineSessionPtr SessionInterface;
	const TSharedPtr<FOnlineSessionSearch>& SessionSearch = MakeShareable(new FOnlineSessionSearch());

	TArray<FOnlineSessionSearchResult> SearchResults;
};
