#pragma once
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"

DEFINE_LOG_CATEGORY_STATIC(LogHttpClient, All, All);

class HttpClient
{
private:
	inline const static FString URL = TEXT("http://localhost:8080");

public:
	static void GetRequest(const FString Subroute,
	                       FString AccessToken,
	                       const TFunction<void(
		                       FHttpRequestPtr Request,
		                       FHttpResponsePtr Response,
		                       bool bWasSuccessful)>
	                       Response)
	{
		const auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("GET");
		Request->OnProcessRequestComplete().BindLambda(Response);

		UE_LOG(LogHttpClient, Display, TEXT("Get request URL: %s"), *(URL + Subroute))

		Send(Request);
	}

	static void PostRequest(const FString Subroute,
	                        FString ContentJsonString,
	                        FString AccessToken,
	                        const TFunction<void(
		                        FHttpRequestPtr Request,
		                        FHttpResponsePtr Response,
		                        bool bWasSuccessful)> Response)
	{
		const auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("POST");
		Request->SetContentAsString(ContentJsonString);
		Request->OnProcessRequestComplete().BindLambda(Response);

		UE_LOG(LogHttpClient, Display, TEXT("Post request URL: %s"), *(URL + Subroute))
		UE_LOG(LogHttpClient, Display, TEXT("Post request data: %s"), *ContentJsonString)
		
		Send(Request);
	}

	static void PutRequest(const FString Subroute,
	                       FString ContentJsonString,
	                       FString AccessToken,
	                       const TFunction<void(
		                       FHttpRequestPtr Request,
		                       FHttpResponsePtr Response,
		                       bool bWasSuccessful)> Response)
	{
		const auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("PUT");
		Request->SetContentAsString(ContentJsonString);
		Request->OnProcessRequestComplete().BindLambda(Response);

		UE_LOG(LogHttpClient, Display, TEXT("Put request URL: %s"), *(URL + Subroute))
		UE_LOG(LogHttpClient, Display, TEXT("Put request data: %s"), *ContentJsonString)
		
		Send(Request);
	}

	static void DeleteRequest(const FString Subroute,
	                          FString AccessToken,
	                          const TFunction<void(
		                          FHttpRequestPtr Request,
		                          FHttpResponsePtr Response,
		                          bool bWasSuccessful)> Response)
	{
		const auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("DELETE");
		Request->OnProcessRequestComplete().BindLambda(Response);

		UE_LOG(LogHttpClient, Display, TEXT("Delete request URL: %s"), *(URL + Subroute))
		
		Send(Request);
	}

private:
	static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> RequestWithRoute(const FString Subroute, FString AccessToken)
	{
		const auto Http = &FHttpModule::Get();
		auto Request = Http->CreateRequest();
		Request->SetURL(URL + Subroute);
		Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
		Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
		Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));

		if (!AccessToken.IsEmpty())
		{
			Request->SetHeader(TEXT("Authorization"), "Bearer " + AccessToken);
		}
		return Request;
	}

	static void Send(const TSharedRef<IHttpRequest, ESPMode::ThreadSafe>& Request)
	{
		Request->ProcessRequest();
	}
};
