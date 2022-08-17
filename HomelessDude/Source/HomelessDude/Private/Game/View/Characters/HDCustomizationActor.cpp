// Fill out your copyright notice in the Description page of Project Settings.


#include "HDCustomizationActor.h"


AHDCustomizationActor::AHDCustomizationActor()
{
	PrimaryActorTick.bCanEverTick = false;

	CustomizationComponent = CreateDefaultSubobject<UHDCustomizationComponent>("CustomizationComponent");
}

void AHDCustomizationActor::BeginPlay()
{
	Super::BeginPlay();

	CustomizationComponent->Init();
}

