// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HDLoginView.h"

#include "Game/View/HDGameInstance.h"
#include "Kismet/GameplayStatics.h"

UHDLoginView::UHDLoginView()
{
	ViewName = EMenuViewName::Login;
}

void UHDLoginView::OnClick_Registration()
{
	LoginBut->SetIsEnabled(false);
	const auto GameInstance = Cast<UHDGameInstance>(GetGameInstance());
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
			UGameplayStatics::OpenLevel(this, "GameplayMap");
		});
}

void UHDLoginView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (LoginBut)
	{
		LoginBut->OnClicked.AddDynamic(this, &UHDLoginView::OnClick_Registration);
	}
}
