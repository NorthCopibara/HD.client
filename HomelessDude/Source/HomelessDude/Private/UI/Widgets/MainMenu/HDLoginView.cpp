// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HDLoginView.h"

#include "Game/View/HDGameInstance.h"
#include "Game/View/GameModes/HDMainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HDMainMenuHUD.h"

UHDLoginView::UHDLoginView()
{
	ViewName = EMenuViewName::Login;
}

void UHDLoginView::OnClick_Login()
{
	LoginBut->SetIsEnabled(false);
	
	if (!GameInstance) return;
	GameInstance->Login(
		Text_Username->GetText().ToString(),
		Text_Password->GetText().ToString(),
		[&](bool Result)
		{
			if (!Result)
			{
				LoginBut->SetIsEnabled(true);
				return;
			}
			
			UE_LOG(LogTemp, Warning, TEXT("Login"))
			
			const auto GameMode = Cast<AHDMainMenuGameMode>(UGameplayStatics::GetGameMode(this));
			if(!GameMode)
			{
				UE_LOG(LogTemp, Error, TEXT("Game mode not found"))
				return;
			}
			GameMode->LoadPlayerCharacters();
		});
}

void UHDLoginView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (LoginBut)
	{
		LoginBut->OnClicked.AddDynamic(this, &UHDLoginView::OnClick_Login);
	}

	GameInstance = Cast<UHDGameInstance>(GetGameInstance());
	if(!GameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("HD Game instance not found!"))
	}
}
