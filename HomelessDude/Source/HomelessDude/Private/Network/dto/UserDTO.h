#pragma once

#include "UserDTO.generated.h"

USTRUCT(BlueprintType)
struct FUserDTO
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	FString username;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	FString password;
};