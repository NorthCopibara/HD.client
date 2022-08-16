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
	bool isSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	TArray<FCharacterMeshConfigDTO> CharacterMeshConfigsDTO;

	FCharacterDTO(const FString& Name, bool bIsSelected,
	              const TArray<FCharacterMeshConfigDTO>& CharacterMeshConfigsDto)
		: name(Name),
		  isSelected(bIsSelected),
		  CharacterMeshConfigsDTO(CharacterMeshConfigsDto)
	{
	}

	FCharacterDTO() = default;
};
