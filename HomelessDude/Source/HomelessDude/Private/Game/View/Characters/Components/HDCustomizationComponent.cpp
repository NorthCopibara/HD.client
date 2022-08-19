// Fill out your copyright notice in the Description page of Project Settings.


#include "HDCustomizationComponent.h"

#include "BaseTypes/CustomizationElements.h"


UHDCustomizationComponent::UHDCustomizationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHDCustomizationComponent::Init()
{
	HideAllMeshes();
}


void UHDCustomizationComponent::RefreshMeshes(TArray<FCustomizationConfig> Configs)
{
	HideAllMeshes();

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
	
	//TODO:
	
	ChangeMeshVisibility(*CustomizationElements[ECustomizationElement::HD_Hands].MeshComponentsNames[0], true);
	ChangeMeshVisibility(*CustomizationElements[ECustomizationElement::HD_Head].MeshComponentsNames[0], true);

	CurrentConfigs = Configs;
}

TArray<FCustomizationConfig> UHDCustomizationComponent::GetCurrentMeshConfigs()
{
	return CurrentConfigs;
}

void UHDCustomizationComponent::ChangeMeshVisibility(FName MeshName, bool IsVisible)
{
	const auto Owner = GetOwner();
	const auto MeshComponent = Cast<USkeletalMeshComponent>(Owner->GetDefaultSubobjectByName(MeshName));
	if (!MeshComponent) return;
	MeshComponent->SetVisibility(IsVisible);
}

void UHDCustomizationComponent::HideAllMeshes()
{
	for (auto CustomizationElement : CustomizationElements)
	{
		for (auto MeshName : CustomizationElement.Value.MeshComponentsNames)
		{
			ChangeMeshVisibility(*MeshName, false);
		}
	}
}
