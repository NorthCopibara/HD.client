// Fill out your copyright notice in the Description page of Project Settings.


#include "HGGameInstance.h"

#include "Network/dto/TokenDTO.h"
#include "Network/Requests/LoginRequest.h"
#include "Network/Requests/RegistrationRequest.h"

void UHGGameInstance::Login(FString Username, FString Password)
{
	if(AuthPlayer && !AuthPlayer->GetAuthToken().IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is already authenticate"))
		return;
	}
	
	const FUserDTO User(Username, Password);
	
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

			GetPlayer()->SetAuthToken(TokenDTO.accessToken);

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *TokenDTO.accessToken)
		});
}

//TODO
void UHGGameInstance::Logout()
{
}

void UHGGameInstance::Registration(FString Username, FString Password)
{
	if(AuthPlayer && !AuthPlayer->GetAuthToken().IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is already authenticate"))
		return;
	}
	
	const FUserDTO User(Username, Password);
	
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

			GetPlayer()->SetAuthToken(TokenDTO.accessToken);

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *TokenDTO.accessToken)
		});
}

FString UHGGameInstance::GetAuthToken()
{
	return GetPlayer()->GetAuthToken();
}

Player* UHGGameInstance::GetPlayer()
{
	if(!AuthPlayer)
	{
		AuthPlayer = MakeShared<Player>();
	}
	return AuthPlayer.Get();
}
