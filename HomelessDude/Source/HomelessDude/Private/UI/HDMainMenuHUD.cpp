// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HDMainMenuHUD.h"

#include "Blueprint/UserWidget.h"

void AHDMainMenuHUD::Show(EMenuViewName viewType)
{
	const auto OwnerView = GetViewByType(viewType);
	if (OwnerView)
	{
		OwnerView->AddToViewport();

		const auto MenuView = Cast<UHDBaseView>(OwnerView);
		if(MenuView)
		{
			MenuView->Init();
		}
	}
}

void AHDMainMenuHUD::Revert(EMenuViewName viewType)
{
	const auto OwnerView = GetViewByType(viewType);
	if (OwnerView)
	{
		const auto MenuView = Cast<UHDBaseView>(OwnerView);
		if(MenuView)
		{
			MenuView->Revert();
		}
	}
	
}

void AHDMainMenuHUD::Hide(EMenuViewName viewType)
{
	const auto OwnerView = GetViewByType(viewType);
	if (OwnerView)
	{
		const auto MenuView = Cast<UHDBaseView>(OwnerView);
		if(MenuView)
		{
			MenuView->Revert();
		}
		
		OwnerView->RemoveFromViewport();
	}
}

void AHDMainMenuHUD::SetCursor(bool isVisible)
{
	if (!GetWorld()) return;

	const auto Controller = GetWorld()->GetFirstPlayerController();
	if (Controller)
	{
		Controller->SetShowMouseCursor(isVisible);
	}
}

void AHDMainMenuHUD::InitViews()
{
	if(!GetWorld()) return;
	
	for (auto Widget : UserWidgets)
	{
		auto Instance = CreateWidget<UHDBaseView>(GetWorld(), Widget.Get());
		auto Type = Instance->GetViewName();

		ViewInstances.Add(Type, Instance);
	}
}

void AHDMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	
	InitViews();
	Show(EMenuViewName::Main);
}

UUserWidget* AHDMainMenuHUD::GetViewByType(EMenuViewName ViewType)
{
	const auto BaseWidget = ViewInstances.Find(ViewType);
	if(!BaseWidget) return nullptr;
	const auto Widget = Cast<UUserWidget>(*BaseWidget);
	if(!Widget) return nullptr;
	return Widget;
}
