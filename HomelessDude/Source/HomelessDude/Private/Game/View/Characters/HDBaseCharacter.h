// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSCharacter.h"
#include "HDBaseCharacter.generated.h"

UENUM(BlueprintType)
enum class ECustomizationElement : uint8
{
	Hair,
	Head,
	Beard,
	Body,
	Hands,
	Legs
};

USTRUCT(BlueprintType)
struct FCustomizationConfig
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customization")
	ECustomizationElement CustomizationElement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customization")
	int32 ActiveElement;
};

USTRUCT(BlueprintType)
struct FCustomizationMeshes
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customization")
	int32 DefaultElement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customization")
	TArray<FString> MeshComponentsNames;

	UPROPERTY(VisibleDefaultsOnly, Category = "Customization")
	TArray<USkeletalMeshComponent*> Meshes;
};

UCLASS()
class HOMELESSDUDE_API AHDBaseCharacter : public AALSCharacter
{
	GENERATED_BODY()

public:
	AHDBaseCharacter(const FObjectInitializer& ObjectInitializer);

	void UpdateMeshes(TArray<FCustomizationConfig> Configs);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Customization")
	TMap<ECustomizationElement, FCustomizationMeshes> CustomizationElements;

	//Test
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<FCustomizationConfig> TestConfig;

	UFUNCTION(BlueprintCallable, Category = "Tests")
	void TestUpdate() { UpdateMeshes(TestConfig); }

private:
	void ChangeMeshVisibility(FName MeshName, bool IsVisible);
};
