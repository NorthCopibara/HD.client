// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HGRegistrationView.h"

#include "Game/View/HGGameInstance.h"
#include "Kismet/GameplayStatics.h"

UHGRegistrationView::UHGRegistrationView()
{
	ViewName = EMenuViewName::Registration;
}

void UHGRegistrationView::OnClick_Registration()
{
	RegistrationBut->SetIsEnabled(false);
	const auto GameInstance = Cast<UHGGameInstance>(GetGameInstance());
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
			UGameplayStatics::OpenLevel(this, "GameplayMap");
		});
}

void UHGRegistrationView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (RegistrationBut)
	{
		RegistrationBut->OnClicked.AddDynamic(this, &UHGRegistrationView::OnClick_Registration);
	}
}
