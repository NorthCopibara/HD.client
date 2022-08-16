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
		const auto RequestAddress = "/menu/selection/" + TargetCharacterId;
		HttpService::GetRequest(RequestAddress, Token, Response);
	}
};
