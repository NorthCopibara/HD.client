#pragma once

#include "TokenDTO.generated.h"

USTRUCT()
struct FTokenDTO
{
	GENERATED_BODY()
	
	UPROPERTY()
	FString accessToken;
};