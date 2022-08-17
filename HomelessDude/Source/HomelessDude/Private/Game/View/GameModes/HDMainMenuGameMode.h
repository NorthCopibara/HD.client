// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Network/Models/CharacterModel.h"
#include "HDMainMenuGameMode.generated.h"

UCLASS()
class AHDMainMenuGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AHDMainMenuGameMode();

	void LoadPlayerCharacters();

	void NextPlayerCharacter();
	void PreviousPlayerCharacter();

	FString GetSelectedCharacterName();
	int32 GetCountCharacters() const;
	
private:
	TArray<FCharacterModel> PlayerCharacters;

	int32 SelectedPlayerCharacterId = 0;

	UHDCustomizationComponent* GetCustomizationComponent();
};
