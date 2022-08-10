// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLogin.h"

#include "Game/View/HGGameInstance.h"

void ATestLogin::Login()
{
	const auto GameInstance = Cast<UHGGameInstance>(GetGameInstance());
	if(!GameInstance) return;
	GameInstance->Login(Username, Password);
}

void ATestLogin::Registration()
{
	const auto GameInstance = Cast<UHGGameInstance>(GetGameInstance());
	if(!GameInstance) return;
	GameInstance->Registration(Username, Password);
}

