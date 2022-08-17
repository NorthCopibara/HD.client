// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HDCustomizationComponent.h"
#include "HDCustomizationActor.generated.h"

UCLASS()
class HOMELESSDUDE_API AHDCustomizationActor : public APawn
{
	GENERATED_BODY()

public:
	AHDCustomizationActor();

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UHDCustomizationComponent* CustomizationComponent = nullptr;
};
