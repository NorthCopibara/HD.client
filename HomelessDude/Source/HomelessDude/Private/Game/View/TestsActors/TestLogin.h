// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestLogin.generated.h"

UCLASS()
class HOMELESSDUDE_API ATestLogin : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;


private:
	FString AccessToken = "";
};
