﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "HDBaseCharacter.h"


AHDBaseCharacter::AHDBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void AHDBaseCharacter::UpdateMeshes(TArray<FCustomizationConfig> Configs)
{
	for (auto CustomizationElement : CustomizationElements)
	{
		CustomizationElement.Value.Meshes.Empty();

		for (auto MeshName : CustomizationElement.Value.MeshComponentsNames)
		{
			ChangeMeshVisibility(*MeshName, false);
		}
	}

	for (const auto Config : Configs)
	{
		if (CustomizationElements.Contains(Config.CustomizationElement))
		{
			const auto CustomizationElement = CustomizationElements[Config.CustomizationElement];
			if (CustomizationElement.MeshComponentsNames.IsValidIndex(Config.ActiveElement))
			{
				ChangeMeshVisibility(*CustomizationElement.MeshComponentsNames[Config.ActiveElement],
				                     !CustomizationElement.MeshComponentsNames[Config.ActiveElement].IsEmpty());
			}
			else
			{
				if (CustomizationElement.MeshComponentsNames.IsValidIndex(CustomizationElement.DefaultElement))
				{
					ChangeMeshVisibility(*CustomizationElement.MeshComponentsNames[CustomizationElement.DefaultElement],
					                     !CustomizationElement.MeshComponentsNames[CustomizationElement.DefaultElement].
					                     IsEmpty());
				}
			}
		}
	}
}

void AHDBaseCharacter::ChangeMeshVisibility(FName MeshName, bool IsVisible)
{
	const auto MeshComponent = Cast<USkeletalMeshComponent>(
		GetDefaultSubobjectByName(MeshName));
	if (!MeshComponent) return;
	MeshComponent->SetVisibility(IsVisible);
}