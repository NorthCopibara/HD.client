#pragma once

#include "JsonObjectConverter.h"
#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpService.h"
#include "Network/dto/UserDTO.h"

class RegistrationRequest
{
public:
	static void Send(FUserDTO RequestData,
	                        const TFunction<void(
		                        FHttpRequestPtr Request,
		                        FHttpResponsePtr Response,
		                        bool bWasSuccessful)>
	                        Response = nullptr)
	{
		FString ContentJsonString;
		FJsonObjectConverter::UStructToJsonObjectString(RequestData.StaticStruct(),
		                                                &RequestData,
		                                                ContentJsonString,
		                                                0,
		                                                0);

		HttpService::PostRequest("/auth/registration", ContentJsonString, "", Response);
	}
};
