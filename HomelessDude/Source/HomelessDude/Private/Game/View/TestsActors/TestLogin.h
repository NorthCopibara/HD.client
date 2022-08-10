// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Network/dto/UserDTO.h"
#include "TestLogin.generated.h"

UCLASS()
class HOMELESSDUDE_API ATestLogin : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
	FUserDTO User;

	UFUNCTION(BlueprintCallable, Category = "Network")
	void Login();

	UFUNCTION(BlueprintCallable, Category = "Network")
	void Registration();
	
private:
	FString AccessToken = "";
};
