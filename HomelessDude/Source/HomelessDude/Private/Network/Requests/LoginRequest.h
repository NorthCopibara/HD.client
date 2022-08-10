#pragma once

#include "JsonObjectConverter.h"
#include "Interfaces/IHttpRequest.h"
#include "Network/Core/HttpService.h"
#include "LoginRequest.generated.h"

USTRUCT()
struct FAuthRequest
{
	GENERATED_BODY()

	UPROPERTY()
	FString username;

	UPROPERTY()
	FString password;
};

USTRUCT()
struct FAuthResponse
{
	GENERATED_BODY()
	
	UPROPERTY()
	FString accessToken;
};

class LoginRequest
{
public:
	static void AuthRequest(FAuthRequest RequestData,
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

		HttpService::PostRequest("/auth/login", ContentJsonString, "", Response);
	}
};
