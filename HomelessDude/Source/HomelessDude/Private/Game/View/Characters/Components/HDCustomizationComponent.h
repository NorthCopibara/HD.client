// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HDCustomizationComponent.generated.h"

UENUM(BlueprintType)
enum class ECustomizationElement : uint8
{
	Hair = 0,
	Head = 1,
	Beard = 2,
	Body = 4,
	Hands = 8,
	Legs = 16
};

USTRUCT(BlueprintType)
struct FCustomizationConfig
{
	GENERATED_BODY()

	FCustomizationConfig() = default;

	FCustomizationConfig(ECustomizationElement CustomizationElement, int32 ActiveElement = 0)
		: CustomizationElement(CustomizationElement),
		  ActiveElement(ActiveElement)
	{
	}

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

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HOMELESSDUDE_API UHDCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHDCustomizationComponent();


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
