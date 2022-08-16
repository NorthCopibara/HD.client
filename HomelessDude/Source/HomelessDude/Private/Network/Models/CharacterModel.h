#pragma once

#include "CharacterModel.generated.h"

struct FCustomizationConfig;

USTRUCT(BlueprintType)
struct FCharacterModel
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character")
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character")
	TArray<FCustomizationConfig> MeshConfigs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character")
	bool IsSelected;

	FCharacterModel(const FString& Name, const TArray<FCustomizationConfig>& MeshConfigs, bool bIsSelected)
		: Name(Name),
		  MeshConfigs(MeshConfigs),
		  IsSelected(bIsSelected)
	{
	}
};
