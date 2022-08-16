#pragma once

#include "JsonObjectConverter.h"
#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpService.h"
#include "Network/dto/CharacterDTO.h"

class CreateCharacterRequest
{
public:
	static void Send(FString Token,
	                 FCharacterDTO RequestData,
	                 const TFunction<void(
		                 FHttpRequestPtr Request,
		                 FHttpResponsePtr Response,
		                 bool bWasSuccessful)> Response)
	{
		FString ContentJsonString;
		FJsonObjectConverter::UStructToJsonObjectString(RequestData.StaticStruct(),
		                                                &RequestData,
		                                                ContentJsonString,
		                                                0,
		                                                0);

		HttpService::PostRequest("/menu/create", Token, ContentJsonString, Response);
	}
};
