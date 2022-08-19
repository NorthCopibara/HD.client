// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTypes/CustomizationElements.h"
#include "Components/ActorComponent.h"
#include "HDCustomizationComponent.generated.h"

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
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HOMELESSDUDE_API UHDCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customization")
	TMap<ECustomizationElement, FCustomizationMeshes> CustomizationElements;

private:
	TArray<FCustomizationConfig> CurrentConfigs;

public:
	UHDCustomizationComponent();

	void Init();
	void RefreshMeshes(TArray<FCustomizationConfig> Configs);
	TArray<FCustomizationConfig> GetCurrentMeshConfigs();

private:
	void ChangeMeshVisibility(FName MeshName, bool IsVisible);
	void HideAllMeshes();
};
