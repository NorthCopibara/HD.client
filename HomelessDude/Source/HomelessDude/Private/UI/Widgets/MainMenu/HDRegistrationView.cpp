// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HDRegistrationView.h"

#include "Game/View/HDGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HDMainMenuHUD.h"

UHDRegistrationView::UHDRegistrationView()
{
	ViewName = EMenuViewName::Registration;
}

void UHDRegistrationView::OnClick_Registration()
{
	RegistrationBut->SetIsEnabled(false);
	const auto GameInstance = Cast<UHDGameInstance>(GetGameInstance());
	if (!GameInstance) return;
	GameInstance->Registration(
		Text_Username->GetText().ToString(),
		Text_Password->GetText().ToString(),
		[&](bool Result)
		{
			if (!Result)
			{
				RegistrationBut->SetIsEnabled(true);
				return;
			}
			//TODO: transits
			//UGameplayStatics::OpenLevel(this, "GameplayMap");

			//TODO: create transitions
			const auto Hud = Cast<AHDMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
			if (!Hud) return;

			Hud->Hide(EMenuViewName::Registration);
			Hud->Show(EMenuViewName::CreateCharacter);
		});
}

void UHDRegistrationView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (RegistrationBut)
	{
		RegistrationBut->OnClicked.AddDynamic(this, &UHDRegistrationView::OnClick_Registration);
	}
}
