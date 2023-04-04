// Fill out your copyright notice in the Description page of Project Settings.


#include "KiberGameInstance.h"

void UKiberGameInstance::Init()
{
	Super::Init();

}

AKiberGameSession* UKiberGameInstance::GetGameSession() const
{
	UWorld* const World = GetWorld();
	if (World)
	{
		AGameModeBase* const Game = World->GetAuthGameMode();
		if (Game)
		{
			return  Cast<AKiberGameSession>(Game->GameSession);
		}
	}

	return nullptr;
}

bool UKiberGameInstance::FindSessions(ULocalPlayer* PlayerOwner, bool bIsDedicatedServer, bool bLANMatch)
{
	bool bResult = false;

	check(PlayerOwner != nullptr);
	if (PlayerOwner)
	{
		AKiberGameSession* const GameSession = GetGameSession();
		if (GameSession)
		{
			GameSession->OnFindSessionsComplete().RemoveAll(this);
			OnSearchSessionsCompleteDelegateHandle = GameSession->OnFindSessionsComplete().AddUObject(this, &UKiberGameInstance::OnSearchSessionsComplete);

			GameSession->FindSessions(PlayerOwner->GetPreferredUniqueNetId().GetUniqueNetId(), NAME_GameSession, true, !bIsDedicatedServer);

			bResult = true;
		}
	}

	return bResult;
}

bool UKiberGameInstance::HostGame(ULocalPlayer* LocalPlayer, const FString& GameType, const FString& InTravelURL)
{
	return false;
}

bool UKiberGameInstance::JoinSession(ULocalPlayer* LocalPlayer, int32 SessionIndexInSearchResults)
{
	AKiberGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		//AddNetworkFailureHandlers();

		//OnJoinSessionCompleteDelegateHandle = GameSession->OnJoinSessionComplete().AddUObject(this, &UKiberGameInstance::OnJoinSessionComplete);
		if (GameSession->JoinSession(LocalPlayer->GetPreferredUniqueNetId().GetUniqueNetId(), NAME_GameSession, SessionIndexInSearchResults))
		{
			return true;
		}
	}

	return false;
}

bool UKiberGameInstance::JoinSession(ULocalPlayer* LocalPlayer, const FOnlineSessionSearchResult& SearchResult)
{
	// needs to tear anything down based on current state?
	AKiberGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		//AddNetworkFailureHandlers();

		//OnJoinSessionCompleteDelegateHandle = GameSession->OnJoinSessionComplete().AddUObject(this, &UShooterGameInstance::OnJoinSessionComplete);
		if (GameSession->JoinSession(LocalPlayer->GetPreferredUniqueNetId().GetUniqueNetId(), NAME_GameSession, SearchResult))
		{
				return true;
		}
	}

	return false;
}

void UKiberGameInstance::OnSearchSessionsComplete(bool bWasSuccessful)
{
	
}

