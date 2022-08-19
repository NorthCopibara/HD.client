// Fill out your copyright notice in the Description page of Project Settings.


#include "HDCreateCharacterView.h"

#include "Game/View/Characters/HDCustomizationActor.h"
#include "Game/View/GameModes/HDMainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"

//TODO: REFACTOR THIS G

UHDCreateCharacterView::UHDCreateCharacterView()
{
	ViewName = EMenuViewName::CreateCharacter;
}

void UHDCreateCharacterView::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CustomizationConfigs.Add(ECustomizationElement::HD_Beard, FCustomizationConfig{ECustomizationElement::HD_Beard});
	CustomizationConfigs.Add(ECustomizationElement::HD_Body, FCustomizationConfig{ECustomizationElement::HD_Body});
	CustomizationConfigs.Add(ECustomizationElement::HD_Hair, FCustomizationConfig{ECustomizationElement::HD_Hair});
	CustomizationConfigs.Add(ECustomizationElement::HD_Hands, FCustomizationConfig{ECustomizationElement::HD_Hands});
	CustomizationConfigs.Add(ECustomizationElement::HD_Head, FCustomizationConfig{ECustomizationElement::HD_Head});
	CustomizationConfigs.Add(ECustomizationElement::HD_Legs, FCustomizationConfig{ECustomizationElement::HD_Legs});

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

	if (Create) Create->OnClicked.AddDynamic(this, &UHDCreateCharacterView::OnClick_Create);
}

void UHDCreateCharacterView::Revert()
{
	Create->SetIsEnabled(true);
}

void UHDCreateCharacterView::OnClick_Legs_1()
{
	Legs_2->SetIsEnabled(true);
	Legs_1->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::HD_Legs].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Legs_2()
{
	Legs_2->SetIsEnabled(false);
	Legs_1->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::HD_Legs].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Body_1()
{
	Body_1->SetIsEnabled(false);
	Body_2->SetIsEnabled(true);
	Body_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::HD_Body].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Body_2()
{
	Body_1->SetIsEnabled(true);
	Body_2->SetIsEnabled(false);
	Body_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::HD_Body].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Body_3()
{
	Body_1->SetIsEnabled(true);
	Body_2->SetIsEnabled(true);
	Body_3->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::HD_Body].ActiveElement = 2;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Beard_1()
{
	Beard_1->SetIsEnabled(false);
	Beard_2->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::HD_Beard].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Beard_2()
{
	Beard_1->SetIsEnabled(true);
	Beard_2->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::HD_Beard].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Hair_1()
{
	Hair_1->SetIsEnabled(false);
	Hair_2->SetIsEnabled(true);
	Hair_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::HD_Hair].ActiveElement = 0;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Hair_2()
{
	Hair_1->SetIsEnabled(true);
	Hair_2->SetIsEnabled(false);
	Hair_3->SetIsEnabled(true);

	CustomizationConfigs[ECustomizationElement::HD_Hair].ActiveElement = 1;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Hair_3()
{
	Hair_1->SetIsEnabled(true);
	Hair_2->SetIsEnabled(true);
	Hair_3->SetIsEnabled(false);

	CustomizationConfigs[ECustomizationElement::HD_Hair].ActiveElement = 2;

	UpdateCharacter();
}

void UHDCreateCharacterView::OnClick_Create()
{
	//TODO: disable all buttons
	Create->SetIsEnabled(false);
	
	const auto GameMode = Cast<AHDMainMenuGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("Game mode not found!"))
		return;
	}
	
	GameMode->CreateNewCharacter(CharName->GetText().ToString());
}

void UHDCreateCharacterView::UpdateCharacter()
{
	TArray<FCustomizationConfig> Configs;
	for (auto Config : CustomizationConfigs)
	{
		Configs.Add(Config.Value);
	}

	const auto GameMode = Cast<AHDMainMenuGameMode>(UGameplayStatics::GetGameMode(this));
	if (!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("Game mode not found!"))
		return;
	}
	
	GameMode->UpdateCustomizationCharacterMesh(Configs);
}
