// Fill out your copyright notice in the Description page of Project Settings.


#include "HDGameInstance.h"

#include "Network/dto/TokenDTO.h"
#include "Network/Extensions/NetworkExtensions.h"
#include "Network/Requests/LoginRequest.h"
#include "Network/Requests/RegistrationRequest.h"

void UHDGameInstance::Login(FString Username, FString Password, const TFunction<void(bool bWasSuccessful)> Result)
{
	if (AuthPlayer && !AuthPlayer->GetAuthToken().IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is already authenticate"))
		if (Result) Result(false);
		return;
	}

	const FUserDTO User(Username, Password);
	LoginRequest::Send(
		User,
		[&, Result](FHttpRequestPtr Request,
		    FHttpResponsePtr Response,
		    bool bWasSuccessful)
		{
			if (!NetworkExtensions::ResponseIsValid(Response, bWasSuccessful))
			{
				//TODO: handle ecxeption
				if (Result) Result(false);
				return;
			};

			FTokenDTO TokenDTO;
			const FString JsonString = Response->GetContentAsString();

			FJsonObjectConverter::JsonObjectStringToUStruct<FTokenDTO>(
				JsonString, &TokenDTO, 0, 0);

			GetPlayer()->SetAuthToken(TokenDTO.accessToken);

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *TokenDTO.accessToken)
			
			//TODO: handle exception
			if (Result) Result(!TokenDTO.accessToken.IsEmpty());
		});
}

//TODO
void UHDGameInstance::Logout()
{
}

void UHDGameInstance::Registration(FString Username,
                                   FString Password,
                                   const TFunction<void(bool bWasSuccessful)> Result)
{
	if (AuthPlayer && !AuthPlayer->GetAuthToken().IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is already authenticate"))
		if (Result) Result(false);
		return;
	}

	const FUserDTO User(Username, Password);
	RegistrationRequest::Send(
		User,
		[&, Result](FHttpRequestPtr Request,
		    FHttpResponsePtr Response,
		    bool bWasSuccessful)
		{
			if (!NetworkExtensions::ResponseIsValid(Response, bWasSuccessful))
			{
				UE_LOG(LogTemp, Error, TEXT("TODO: handle exception!!!"))
				if (Result) Result(false);
				return;
			};

			FTokenDTO TokenDTO;
			const FString JsonString = Response->GetContentAsString();

			FJsonObjectConverter::JsonObjectStringToUStruct<FTokenDTO>(
				JsonString, &TokenDTO, 0, 0);

			GetPlayer()->SetAuthToken(TokenDTO.accessToken);

			if (Result) Result(!JsonString.IsEmpty());

			UE_LOG(LogTemp, Warning, TEXT("Test: response = %s"), *JsonString)
			UE_LOG(LogTemp, Warning, TEXT("Test: access tocken = %s"), *TokenDTO.accessToken)
		});
}

FString UHDGameInstance::GetAuthToken()
{
	return GetPlayer()->GetAuthToken();
}

Player* UHDGameInstance::GetPlayer()
{
	if (!AuthPlayer)
	{
		AuthPlayer = MakeShared<Player>();
	}
	return AuthPlayer.Get();
}
