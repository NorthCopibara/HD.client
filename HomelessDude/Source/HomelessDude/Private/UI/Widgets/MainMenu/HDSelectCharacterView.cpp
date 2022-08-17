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

	if (NextChar) NextChar->OnClicked.AddDynamic(this, &UHDSelectCharacterView::OnClick_NextChar);
	if (PreviousChar) PreviousChar->OnClicked.AddDynamic(this, &UHDSelectCharacterView::OnClick_PreviousChar);
	if (Select) Select->OnClicked.AddDynamic(this, &UHDSelectCharacterView::OnClick_Select);
	if (CreateChar) CreateChar->OnClicked.AddDynamic(this, &UHDSelectCharacterView::OnClick_CreateChar);
	
	GameMode = Cast<AHDMainMenuGameMode>(UGameplayStatics::GetGameMode(this));
	check(GameMode)
}

void UHDSelectCharacterView::Revert()
{
	SetCharacterName();
	
	const bool HasCharactersMore2 = GameMode->GetCountCharacters() > 1;
	const auto IsVisible = HasCharactersMore2 ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	
	NextChar->SetVisibility(IsVisible);
	NextChar->SetIsEnabled(HasCharactersMore2);
	
	PreviousChar->SetVisibility(IsVisible);
	PreviousChar->SetIsEnabled(HasCharactersMore2);

	Select->SetVisibility(IsVisible);
	Select->SetIsEnabled(HasCharactersMore2);
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
	GameMode->NextPlayerCharacter();
	SetCharacterName();
}

void UHDSelectCharacterView::OnClick_PreviousChar()
{
	GameMode->PreviousPlayerCharacter();
	SetCharacterName();
}

void UHDSelectCharacterView::SetCharacterName()
{
	if(!GameMode) return;
	const auto Name = GameMode->GetSelectedCharacterName();
	if(Name.IsEmpty())
	{
		CharName->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		CharName->SetVisibility(ESlateVisibility::Visible);
		CharName->SetText(FText::FromString(Name));
	}
}
