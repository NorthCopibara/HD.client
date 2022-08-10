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

	FUserDTO(const FString& Username, const FString& Password)
		: username(Username),
		  password(Password)
	{
	}

	FUserDTO() = default;
};