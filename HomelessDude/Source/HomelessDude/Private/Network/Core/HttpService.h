#pragma once
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

class HttpService
{
private:
	inline const static FString URL = TEXT("http://localhost:8080");

public:
	static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> RequestWithRoute(const FString Subroute, FString AccessToken)
	{
		const auto Http = &FHttpModule::Get();
		auto Request = Http->CreateRequest();
		Request->SetURL(URL + Subroute);
		Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
		Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
		Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));

		if (!AccessToken.Equals(""))
		{
			Request->SetHeader(TEXT("Authorization"), "Bearer_" + AccessToken);
		}
		return Request;
	}

	static void GetRequest(const FString Subroute,
	                       FString AccessToken,
	                       const TFunction<void(
		                       FHttpRequestPtr Request,
		                       FHttpResponsePtr Response,
		                       bool bWasSuccessful)>
	                       Response)
	{
		const auto Request = GetRequest(Subroute, AccessToken);
		Request->OnProcessRequestComplete().BindLambda(Response);
		Send(Request);
	}

	static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> GetRequest(FString Subroute, FString AccessToken)
	{
		auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("GET");
		return Request;
	}

	static void PostRequest(const FString Subroute,
	                        FString ContentJsonString,
	                        FString AccessToken,
	                        const TFunction<void(
		                        FHttpRequestPtr Request,
		                        FHttpResponsePtr Response,
		                        bool bWasSuccessful)>
	                        Response)
	{
		const auto Request = PostRequest(Subroute, ContentJsonString, AccessToken);
		Request->OnProcessRequestComplete().BindLambda(Response);
		Send(Request);
	}

	static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> PostRequest(const FString Subroute,
	                                                                 FString ContentJsonString,
	                                                                 FString AccessToken)
	{
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("POST");
		Request->SetContentAsString(ContentJsonString);
		return Request;
	}

	static void PutRequest(const FString Subroute,
	                       FString ContentJsonString,
	                       FString AccessToken,
	                       const TFunction<void(
		                       FHttpRequestPtr Request,
		                       FHttpResponsePtr Response,
		                       bool bWasSuccessful)>
	                       Response)
	{
		const auto Request = PutRequest(Subroute, ContentJsonString, AccessToken);
		Request->OnProcessRequestComplete().BindLambda(Response);
		Send(Request);
	}

	static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> PutRequest(const FString Subroute,
	                                                                FString ContentJsonString,
	                                                                FString AccessToken)
	{
		auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("PUT");
		Request->SetContentAsString(ContentJsonString);
		return Request;
	}

	static void DeleteRequest(const FString Subroute,
	                          FString AccessToken,
	                          const TFunction<void(
		                          FHttpRequestPtr Request,
		                          FHttpResponsePtr Response,
		                          bool bWasSuccessful)>
	                          Response)
	{
		const auto Request = DeleteRequest(Subroute, AccessToken);
		Request->OnProcessRequestComplete().BindLambda(Response);
		Send(Request);
	}


	static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> DeleteRequest(const FString Subroute, FString AccessToken)
	{
		auto Request = RequestWithRoute(Subroute, AccessToken);
		Request->SetVerb("DELETE");
		return Request;
	}
	
	static void Send(const TSharedRef<IHttpRequest, ESPMode::ThreadSafe>& Request)
	{
		Request->ProcessRequest();
	}

	static bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful)
	{
		if (!bWasSuccessful || !Response.IsValid())
		{
			return false;
		}

		if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
		{
			return true;
		}

		//TODO: log
		UE_LOG(LogTemp, Warning, TEXT("Http response returned error code: %d"), Response->GetResponseCode())
		return false;
	}
};
