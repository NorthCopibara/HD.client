// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Network/Models/Player.h"
#include "HGGameInstance.generated.h"

UCLASS()
class HOMELESSDUDE_API UHGGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Login(FString Username, FString Password);
	void Logout();
	void Registration(FString Username, FString Password);

	FString GetAuthToken();
	Player* GetPlayer();
private:
	TSharedPtr<Player> AuthPlayer = nullptr;
};
