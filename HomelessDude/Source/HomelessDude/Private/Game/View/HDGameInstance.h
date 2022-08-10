// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Network/Models/Player.h"
#include "HDGameInstance.generated.h"

UCLASS()
class HOMELESSDUDE_API UHDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Login(FString Username, FString Password, const TFunction<void(bool bWasSuccessful)> Result);
	void Logout();
	void Registration(FString Username, FString Password, const TFunction<void(bool bWasSuccessful)> Result);

	FString GetAuthToken();
	Player* GetPlayer();
private:
	TSharedPtr<Player> AuthPlayer = nullptr;

	//TODO
	TFunction<void(bool bWasSuccessful)> InternalResult = nullptr;
};
