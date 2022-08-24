#pragma once

#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpClient.h"

class GetSelectionCharacterRequest
{
public:
	static void Send(FString Token,
	                 const TFunction<void(
		                 FHttpRequestPtr Request,
		                 FHttpResponsePtr Response,
		                 bool bWasSuccessful)> Response)
	{
		HttpClient::GetRequest("/menu/selection", Token, Response);
	}
};
