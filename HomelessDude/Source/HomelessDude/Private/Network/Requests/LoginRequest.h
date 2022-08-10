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
	FString Username;

	UPROPERTY()
	FString Password;
};

USTRUCT()
struct FAuthData
{
	GENERATED_BODY()

	UPROPERTY()
	FString AccessToken;

	UPROPERTY()
	FString RefreshToken;

	UPROPERTY()
	FString ExpiredIn;
};

USTRUCT()
struct FAuthResponse
{
	GENERATED_BODY()

	UPROPERTY()
	FAuthData LoginResult;
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
