// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MechanicalActors/BaseGameContext.h"

#include "GameplayGameContext.generated.h"

UCLASS()
class HOMELESSDUDE_API AGameplayGameContext : public ABaseGameContext
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
