// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HGMainMenuHUD.h"

#include "Blueprint/UserWidget.h"

void AHGMainMenuHUD::Show(EMenuViewName viewType)
{
	const auto OwnerView = GetViewByType(viewType);
	if (OwnerView)
	{
		OwnerView->AddToViewport();

		const auto MenuView = Cast<UHGBaseView>(OwnerView);
		if(MenuView)
		{
			MenuView->Init();
		}
	}
}

void AHGMainMenuHUD::Hide(EMenuViewName viewType)
{
	const auto OwnerView = GetViewByType(viewType);
	if (OwnerView)
	{
		const auto MenuView = Cast<UHGBaseView>(OwnerView);
		if(MenuView)
		{
			MenuView->Revert();
		}
		
		OwnerView->RemoveFromViewport();
	}
}

void AHGMainMenuHUD::SetCursor(bool isVisible)
{
	if (!GetWorld()) return;

	const auto Controller = GetWorld()->GetFirstPlayerController();
	if (Controller)
	{
		Controller->SetShowMouseCursor(isVisible);
	}
}

void AHGMainMenuHUD::InitViews()
{
	if(!GetWorld()) return;
	
	for (auto Widget : UserWidgets)
	{
		auto Instance = CreateWidget<UHGBaseView>(GetWorld(), Widget.Get());
		auto Type = Instance->GetViewName();

		ViewInstances.Add(Type, Instance);
	}
}

void AHGMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	
	InitViews();
	Show(EMenuViewName::Main);
}

UUserWidget* AHGMainMenuHUD::GetViewByType(EMenuViewName ViewType)
{
	const auto BaseWidget = ViewInstances.Find(ViewType);
	if(!BaseWidget) return nullptr;
	const auto Widget = Cast<UUserWidget>(*BaseWidget);
	if(!Widget) return nullptr;
	return Widget;
}
