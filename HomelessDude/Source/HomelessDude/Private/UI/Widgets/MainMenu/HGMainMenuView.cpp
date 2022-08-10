// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HGMainMenuView.h"

#include "UI/HGMainMenuHUD.h"

UHGMainMenuView::UHGMainMenuView()
{
	ViewName = EMenuViewName::Main;
}

void UHGMainMenuView::OnClick_MoveToLogin()
{
	if(!GetWorld()) return;

	const auto Hud = Cast<AHGMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(!Hud) return;

	Hud->Hide(EMenuViewName::Main);
	Hud->Show(EMenuViewName::Login);
}

void UHGMainMenuView::OnClick_MoveToRegistration()
{
	if(!GetWorld()) return;

	const auto Hud = Cast<AHGMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(!Hud) return;

	Hud->Hide(EMenuViewName::Main);
	Hud->Show(EMenuViewName::Registration);
}

void UHGMainMenuView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(LoginBut)
	{
		LoginBut->OnClicked.AddDynamic(this, &UHGMainMenuView::OnClick_MoveToLogin);
	}

	if(RegistrationBut)
	{
		RegistrationBut->OnClicked.AddDynamic(this, &UHGMainMenuView::OnClick_MoveToRegistration);
	}
}
