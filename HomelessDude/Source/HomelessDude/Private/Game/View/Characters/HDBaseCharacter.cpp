// Fill out your copyright notice in the Description page of Project Settings.


#include "HDBaseCharacter.h"

#include "Game/View/HDGameInstance.h"
#include "Kismet/GameplayStatics.h"


AHDBaseCharacter::AHDBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CustomizationComponent = CreateDefaultSubobject<UHDCustomizationComponent>("CustomizationComponent");
}

void AHDBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(CustomizationComponent)
	
	const auto GameInstance = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("Game instance not found"))
		return;
	}

	CustomizationComponent->RefreshMeshes(GameInstance->GetPlayerCharacterModel().MeshConfigs);
}
