// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HDLoginView.h"

#include "Game/View/HDGameInstance.h"
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
			//TODO: transits

			UE_LOG(LogTemp, Warning, TEXT("Login"))

			//TODO: create transitions
			const auto Hud = Cast<AHDMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
			if (!Hud) return;

			Hud->Hide(EMenuViewName::Login);
			Hud->Show(EMenuViewName::CreateCharacter);
			//UGameplayStatics::OpenLevel(this, "GameplayMap");
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
