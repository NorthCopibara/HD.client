// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLogin.h"

#include "Interfaces/IHttpRequest.h"
#include "Network/Requests/LoginRequest.h"

void ATestLogin::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Test_request"))

	FAuthRequest AuthRequest;
	AuthRequest.username = "Test_2";
	AuthRequest.password = "Test_2";
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

			FAuthResponse AuthResponse;
			const FString JsonString = Response->GetContentAsString();
			FJsonObjectConverter::JsonObjectStringToUStruct<FAuthResponse>(JsonString, &AuthResponse, 0, 0);

			AccessToken = AuthResponse.accessToken;

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *AccessToken)
		});
}

