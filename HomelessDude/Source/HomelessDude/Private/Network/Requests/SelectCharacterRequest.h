#pragma once

#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpClient.h"

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
		HttpClient::GetRequest(RequestAddress, Token, Response);
	}
};
