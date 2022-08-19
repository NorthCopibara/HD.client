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

protected:
	//TODO: move to back
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character")
	FCharacterModel DefaultCharacterConfig;
	
private:
	TArray<FCharacterModel> PlayerCharacters;

	int32 SelectedPlayerCharacterId = 0;
	
public:
	AHDMainMenuGameMode();

	void LoadPlayerCharacters();

	void NextPlayerCharacter();
	void PreviousPlayerCharacter();

	FString GetSelectedCharacterName();
	int32 GetCountCharacters() const;

	void UpdateCustomizationCharacterMesh(TArray<FCustomizationConfig> MeshConfigs);
	
	void TransitToCreatingCharacterView();
	
	void CreateNewCharacter(FString CharacterName);
	void SelectCharacter();
	
private:
	UHDCustomizationComponent* GetCustomizationComponent();

	void InitCharacterFromResponse(FString Response);
};