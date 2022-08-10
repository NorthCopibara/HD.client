// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLogin.h"

#include "Interfaces/IHttpRequest.h"
#include "Network/dto/TokenDTO.h"
#include "Network/Requests/LoginRequest.h"
#include "Network/Requests/RegistrationRequest.h"

void ATestLogin::Login()
{
	LoginRequest::Send(
		User,
		[&](FHttpRequestPtr Request,
			FHttpResponsePtr Response,
			bool bWasSuccessful)
		{
			if (!HttpService::ResponseIsValid(Response, bWasSuccessful))
			{
				UE_LOG(LogTemp, Error, TEXT("TODO: handle exception!!!"))
				return;
			};

			FTokenDTO TokenDTO;
			const FString JsonString = Response->GetContentAsString();
			FJsonObjectConverter::JsonObjectStringToUStruct<FTokenDTO>(JsonString, &TokenDTO, 0, 0);

			AccessToken = TokenDTO.accessToken;

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *AccessToken)
		});
}

void ATestLogin::Registration()
{
	RegistrationRequest::Send(
		User,
		[&](FHttpRequestPtr Request,
			FHttpResponsePtr Response,
			bool bWasSuccessful)
		{
			if (!HttpService::ResponseIsValid(Response, bWasSuccessful))
			{
				UE_LOG(LogTemp, Error, TEXT("TODO: handle exception!!!"))
				return;
			};

			FTokenDTO TokenDTO;
			const FString JsonString = Response->GetContentAsString();
			FJsonObjectConverter::JsonObjectStringToUStruct<FTokenDTO>(JsonString, &TokenDTO, 0, 0);

			AccessToken = TokenDTO.accessToken;

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *AccessToken)
		});
}

