// Fill out your copyright notice in the Description page of Project Settings.


#include "HDSelectCharacterView.h"

#include "Kismet/GameplayStatics.h"

UHDSelectCharacterView::UHDSelectCharacterView()
{
	ViewName = EMenuViewName::SelectCharacter;
}

void UHDSelectCharacterView::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UHDSelectCharacterView::OnClick_Select()
{
	//Select char -> session
	//Move to gameplay
	UGameplayStatics::OpenLevel(this, "GameplayMap");
}

void UHDSelectCharacterView::OnClick_CreateChar()
{
	//Move to create view
	//Show pawn
}

void UHDSelectCharacterView::OnClick_NextChar()
{
}

void UHDSelectCharacterView::OnClick_PreviousChar()
{
}
