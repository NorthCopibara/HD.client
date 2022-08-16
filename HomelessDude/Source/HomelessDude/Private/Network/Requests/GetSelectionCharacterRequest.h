#pragma once

#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpService.h"

class GetSelectionCharacterRequest
{
public:
	static void Send(FString Token,
	                 const TFunction<void(
		                 FHttpRequestPtr Request,
		                 FHttpResponsePtr Response,
		                 bool bWasSuccessful)> Response)
	{
		HttpService::GetRequest("/menu/selection", Token, Response);
	}
};
