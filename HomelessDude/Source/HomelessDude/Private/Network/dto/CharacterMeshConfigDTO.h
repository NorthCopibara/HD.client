#pragma once

#include "CharacterMeshConfigDTO.generated.h"

USTRUCT(BlueprintType)
struct FCharacterMeshConfigDTO
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	FString customElement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	int32 activeElement;

	FCharacterMeshConfigDTO(const FString& customElement, int32 activeElement)
		: customElement(customElement),
		  activeElement(activeElement)
	{
	}

	FCharacterMeshConfigDTO() = default;
};
