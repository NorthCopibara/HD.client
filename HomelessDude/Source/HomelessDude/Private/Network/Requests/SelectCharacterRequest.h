#pragma once

#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpService.h"

class SelectCharacterRequest
{
public:
	static void Send(FString Token,
	                 int32 TargetCharacterId,
	                 const TFunction<void(
		                 FHttpRequestPtr Request,
		                 FHttpResponsePtr Response,
		                 bool bWasSuccessful)> Response)
	{
		const FString RequestAddress = FString::Printf(TEXT("/menu/selection/%i"), TargetCharacterId);
		UE_LOG(LogTemp, Warning, TEXT("Test_url: %s"), *RequestAddress)
		HttpService::GetRequest(RequestAddress, Token, Response);
	}
};
