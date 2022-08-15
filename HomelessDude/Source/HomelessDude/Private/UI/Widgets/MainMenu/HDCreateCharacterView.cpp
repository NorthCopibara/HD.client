// Fill out your copyright notice in the Description page of Project Settings.


#include "HDCreateCharacterView.h"

#include "Game/View/Characters/HDCustomizationActor.h"
#include "Kismet/GameplayStatics.h"

//TODO: REFACTOR THIS G

UHDCreateCharacterView::UHDCreateCharacterView()
{
	ViewName = EMenuViewName::CreateCharacter;
}

void UHDCreateCharacterView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CustomizationConfigs.Add(ECustomizationElement::Beard, FCustomizationConfig{ECustomizationElement::Beard});
	CustomizationConfigs.Add(ECustomizationElement::Body, FCustomizationConfig{ECustomizationElement::Body});
	CustomizationConfigs.Add(ECustomizationElement::Hair, FCustomizationConfig{ECustomizationElement::Hair});
	CustomizationConfigs.Add(ECustomizationElement::Hands, FCustomizationConfig{ECustomizationElement::Hands});
	CustomizationConfigs.Add(ECustomizationElement::Head, FCustomizationConfig{ECustomizationElement::Head});
	CustomizationConfigs.Add(ECustomizationElement::Legs, FCustomizationConfig{ECustomizationElement::Legs});

	const auto CustomizationActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	check(CustomizationActor)
	CustomizationComponent
		= Cast<UHDCustomizationComponent>(CustomizationActor->GetDefaultSubobjectByName("CustomizationComponent"));
	check(CustomizationComponent)

	UpdateCharacter();

	if (Legs_1) Legs_1->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Legs_1);
	Legs_1->SetIsEnabled(false);
	if (Legs_2) Legs_2->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Legs_2);

	if (Body_1) Body_1->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Body_1);
	Body_1->SetIsEnabled(false);
	if (Body_2) Body_2->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Body_2);
	if (Body_3) Body_3->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Body_3);

	if (Beard_1) Beard_1->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Beard_1);
	Beard_1->SetIsEnabled(false);
	if (Beard_2) Beard_2->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Beard_2);

	if (Hair_1) Hair_1->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Hair_1);
	Hair_1->SetIsEnabled(false);
	if (Hair_2) Hair_2->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Hair_2);
	if (Hair_3) Hair_3->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Hair_3);
}

void UHDCreateCharacterView::OnClick_Legs_1()
{
	Legs_2->SetIsEnabled(true);
	Legs_1->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::Legs].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Legs_2()
{
	Legs_2->SetIsEnabled(false);
	Legs_1->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::Legs].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Body_1()
{
	Body_1->SetIsEnabled(false);
	Body_2->SetIsEnabled(true);
	Body_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::Body].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Body_2()
{
	Body_1->SetIsEnabled(true);
	Body_2->SetIsEnabled(false);
	Body_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::Body].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Body_3()
{
	Body_1->SetIsEnabled(true);
	Body_2->SetIsEnabled(true);
	Body_3->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::Body].ActiveElement = 2;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Beard_1()
{
	Beard_1->SetIsEnabled(false);
	Beard_2->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::Beard].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Beard_2()
{
	Beard_1->SetIsEnabled(true);
	Beard_2->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::Beard].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Hair_1()
{
	Hair_1->SetIsEnabled(false);
	Hair_2->SetIsEnabled(true);
	Hair_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::Hair].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Hair_2()
{
	Hair_1->SetIsEnabled(true);
	Hair_2->SetIsEnabled(false);
	Hair_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::Hair].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Hair_3()
{
	Hair_1->SetIsEnabled(true);
	Hair_2->SetIsEnabled(true);
	Hair_3->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::Hair].ActiveElement = 2;

	UpdateCharacter();
}

void UHDCreateCharacterView::UpdateCharacter()
{
	TArray<FCustomizationConfig> Configs;
	for (auto Config : CustomizationConfigs)
	{
		Configs.Add(Config.Value);
	}
	
	CustomizationComponent->UpdateMeshes(Configs);
}
