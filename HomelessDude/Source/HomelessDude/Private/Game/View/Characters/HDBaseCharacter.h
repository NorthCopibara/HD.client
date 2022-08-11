// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSCharacter.h"
#include "HDBaseCharacter.generated.h"

UCLASS()
class HOMELESSDUDE_API AHDBaseCharacter : public AALSCharacter
{
	GENERATED_BODY()

public:
	AHDBaseCharacter(const FObjectInitializer& ObjectInitializer);
};
