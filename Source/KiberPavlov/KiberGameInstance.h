// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystemUtils.h"
#include "Engine/GameInstance.h"
#include "Engine/NetworkDelegates.h"
#include "KiberGameSession.h"
#include "GameFramework/GameModeBase.h"
#include "KiberGameInstance.generated.h"



UCLASS()
class KIBERPAVLOV_API UKiberGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	AKiberGameSession* GetGameSession() const;

	/** Initiates the session searching */
	bool FindSessions(ULocalPlayer* PlayerOwner, bool bIsDedicatedServer, bool bLANMatch);

	bool HostGame(ULocalPlayer* LocalPlayer, const FString& GameType, const FString& InTravelURL);
	bool JoinSession(ULocalPlayer* LocalPlayer, int32 SessionIndexInSearchResults);
	bool JoinSession(ULocalPlayer* LocalPlayer, const FOnlineSessionSearchResult& SearchResult);


private:
	void OnSearchSessionsComplete(bool bWasSuccessful);

	/** Handle to various registered delegates */
	FDelegateHandle TickDelegateHandle;
	FDelegateHandle TravelLocalSessionFailureDelegateHandle;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	FDelegateHandle OnSearchSessionsCompleteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	FDelegateHandle OnEndSessionCompleteDelegateHandle;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	FDelegateHandle OnCreatePresenceSessionCompleteDelegateHandle;
	FDelegateHandle OnGameActivityActivationRequestedDelegateHandle;

};
