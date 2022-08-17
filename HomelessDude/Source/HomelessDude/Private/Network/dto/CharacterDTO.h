#pragma once
#include "CharacterMeshConfigDTO.h"

#include "CharacterDTO.generated.h"

USTRUCT(BlueprintType)
struct FCharacterDTO
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	bool selected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	TArray<FCharacterMeshConfigDTO> characterMeshConfigs;

	FCharacterDTO(const FString& Name, bool bIsSelected,
	              const TArray<FCharacterMeshConfigDTO>& characterMeshConfigsDto)
		: name(Name),
		  selected(bIsSelected),
		  characterMeshConfigs(characterMeshConfigsDto)
	{
	}

	FCharacterDTO() = default;
};
