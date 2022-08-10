// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HGLoginView.h"

#include "Game/View/HGGameInstance.h"
#include "Kismet/GameplayStatics.h"

UHGLoginView::UHGLoginView()
{
	ViewName = EMenuViewName::Login;
}

void UHGLoginView::OnClick_Registration()
{
	LoginBut->SetIsEnabled(false);
	const auto GameInstance = Cast<UHGGameInstance>(GetGameInstance());
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

void UHGLoginView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (LoginBut)
	{
		LoginBut->OnClicked.AddDynamic(this, &UHGLoginView::OnClick_Registration);
	}
}
