// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/MainMenu/HDMainMenuView.h"

#include "UI/HDMainMenuHUD.h"

UHDMainMenuView::UHDMainMenuView()
{
	ViewName = EMenuViewName::Main;
}

void UHDMainMenuView::OnClick_MoveToLogin()
{
	if(!GetWorld()) return;

	const auto Hud = Cast<AHDMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(!Hud) return;

	Hud->Hide(EMenuViewName::Main);
	Hud->Show(EMenuViewName::Login);
}

void UHDMainMenuView::OnClick_MoveToRegistration()
{
	if(!GetWorld()) return;

	const auto Hud = Cast<AHDMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(!Hud) return;

	Hud->Hide(EMenuViewName::Main);
	Hud->Show(EMenuViewName::Registration);
}

void UHDMainMenuView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(LoginBut)
	{
		LoginBut->OnClicked.AddDynamic(this, &UHDMainMenuView::OnClick_MoveToLogin);
	}

	if(RegistrationBut)
	{
		RegistrationBut->OnClicked.AddDynamic(this, &UHDMainMenuView::OnClick_MoveToRegistration);
	}
}
