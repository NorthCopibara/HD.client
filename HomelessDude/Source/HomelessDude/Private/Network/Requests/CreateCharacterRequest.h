#pragma once

#include "JsonObjectConverter.h"
#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpClient.h"
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
		
		HttpClient::PostRequest("/menu/create", ContentJsonString, Token, Response);
	}
};
