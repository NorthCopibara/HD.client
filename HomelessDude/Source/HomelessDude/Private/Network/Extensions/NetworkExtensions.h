#pragma once
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

DEFINE_LOG_CATEGORY_STATIC(LogNetwork, All, All);

class NetworkExtensions
{
public:
	static bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful, FString ErrorMessage = "")
	{
		if (!bWasSuccessful || !Response.IsValid())
		{
			ErrorMessage = "Response failed";
			UE_LOG(LogNetwork, Error, TEXT("%s"), *ErrorMessage)
			
			return false;
		}

		if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
		{
			ErrorMessage = "";
			return true;
		}

		ErrorMessage = Response->GetContentAsString();
		UE_LOG(LogNetwork, Error, TEXT("Http response returned error code: %d"), Response->GetResponseCode())
		UE_LOG(LogNetwork, Error, TEXT("Respounce message: %s"), *ErrorMessage)
		
		return false;
	}
};
