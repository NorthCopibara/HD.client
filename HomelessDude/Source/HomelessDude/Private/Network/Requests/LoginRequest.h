#pragma once

#include "JsonObjectConverter.h"
#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpClient.h"
#include "Network/dto/UserDTO.h"

class LoginRequest
{
public:
	static void Send(FUserDTO RequestData,
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

		HttpClient::PostRequest("/auth/login", ContentJsonString, "", Response);
	}
};
