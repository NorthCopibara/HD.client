﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HDCustomizationComponent.h"
#include "GameFramework/Actor.h"
#include "HDCustomizationActor.generated.h"

UCLASS()
class HOMELESSDUDE_API AHDCustomizationActor : public AActor
{
	GENERATED_BODY()

public:
	AHDCustomizationActor();
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UHDCustomizationComponent* CustomizationComponent = nullptr;
};