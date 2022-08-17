#pragma once
#include "CharacterDTO.h"

#include "SelectionMenuDTO.generated.h"

USTRUCT(BlueprintType)
struct FSelectionMenuDTO
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FCharacterDTO> charactersDTO;

	explicit FSelectionMenuDTO(const TArray<FCharacterDTO>& charactersDto)
		: charactersDTO(charactersDto)
	{
	}

	FSelectionMenuDTO() = default;
};
