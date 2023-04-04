// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "Online.h"
#include "OnlineSubsystemUtils.h"
#include "KiberGameSession.generated.h"

/**
 * 
 */

class FKiberOnlineSessionSettings : public FOnlineSessionSettings
{
public:

	FKiberOnlineSessionSettings(bool bIsLAN = false, bool bIsPresence = false, int32 MaxNumPlayers = 4);
	virtual ~FKiberOnlineSessionSettings() {}
};

/**
 * General search setting for a Shooter game
 */

class FKiberOnlineSearchSettings : public FOnlineSessionSearch
{
public:
	FKiberOnlineSearchSettings(bool bSearchingLAN = false, bool bSearchingPresence = false);

	virtual ~FKiberOnlineSearchSettings() {}
};

struct FKiberGameSessionParams
{
	/** Name of session settings are stored with */
	FName SessionName;
	/** LAN Match */
	bool bIsLAN;
	/** Presence enabled session */
	bool bIsPresence;
	/** Id of player initiating lobby */
	TSharedPtr<const FUniqueNetId> UserId;
	/** Current search result choice to join */
	int32 BestSessionIdx;

	FKiberGameSessionParams()
		: SessionName(NAME_None)
		, bIsLAN(false)
		, bIsPresence(false)
		, BestSessionIdx(0)
	{
	}
};

UCLASS()
class KIBERPAVLOV_API AKiberGameSession : public AGameSession
{
	GENERATED_BODY()
public:

	FOnFindSessionsComplete& OnFindSessionsComplete() { return FindSessionsCompleteEvent; }

	void FindSessions(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence);

	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, int32 SessionIndexInSearchResults);

	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FOnlineSessionSearchResult& SearchResult);

	const TArray<FOnlineSessionSearchResult>& GetSearchResults() const;
protected:
	/** Transient properties of a session during game creation/matchmaking */
	FKiberGameSessionParams CurrentSessionParams;
	/** Current host settings */
	TSharedPtr<class FOnlineSessionSettings> HostSettings;
	/** Current search settings */
	//TSharedPtr<class FOnlineSessionSettings> SearchSettings;

public:
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;

protected:
	void OnFindSessionsComplete(bool bWasSuccessful);

	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	DECLARE_EVENT_OneParam(AKiberGameSession, FOnFindSessionsComplete, bool /*bWasSuccessful*/);
	FOnFindSessionsComplete FindSessionsCompleteEvent;

public:
	/** Current search settings */
	TSharedPtr<class FOnlineSessionSearch> SearchSettings;

public:
	/** Default number of players allowed in a game */
	static const int32 DEFAULT_NUM_PLAYERS = 8;

	/** Default number of players allowed in a game */
	//static const FString DEFAULT_MAP_NAME = "";

};
