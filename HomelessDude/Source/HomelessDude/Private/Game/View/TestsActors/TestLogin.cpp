// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLogin.h"

#include "Interfaces/IHttpRequest.h"
#include "Network/Requests/LoginRequest.h"

void ATestLogin::BeginPlay()
{
	Super::BeginPlay();

	
	UE_LOG(LogTemp, Warning, TEXT("Test_request"))

	FAuthRequest AuthRequest;
	AuthRequest.Username = "Test_1";
	AuthRequest.Password = "Test_1";
	LoginRequest::AuthRequest(
		AuthRequest,
		[&](FHttpRequestPtr Request,
			FHttpResponsePtr Response,
			bool bWasSuccessful)
		{
			if (!HttpService::ResponseIsValid(Response, bWasSuccessful))
			{
				UE_LOG(LogTemp, Error, TEXT("TODO: handle exception!!!"))
				return;
			};

			FAuthData Result;
			const FString JsonString = Response->GetContentAsString();
			FJsonObjectConverter::JsonObjectStringToUStruct<FAuthData>(JsonString, &Result, 0, 0);

			AccessToken = Result.AccessToken;
			RefreshToken = Result.RefreshToken;

			UE_LOG(LogTemp, Display, TEXT("Test: access tocken = %s"), *AccessToken)
			UE_LOG(LogTemp, Display, TEXT("Test: refresh tocken = %s"), *RefreshToken)
		});
}

