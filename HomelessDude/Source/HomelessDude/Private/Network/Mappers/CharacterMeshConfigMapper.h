#pragma once

#include "BaseTypes/CustomizationElements.h"
#include "Game/View/Characters/Components/HDCustomizationComponent.h"
#include "Network/dto/CharacterDTO.h"
#include "Utils/Utils.h"

class CharacterMeshConfigMapper
{
public:
	static FCharacterMeshConfigDTO MapToCharacterMeshConfigDTO(FCustomizationConfig CharacterMeshConfig)
	{
		const UEnum* Enum = StaticEnum<ECustomizationElement>();
		//TODO: move to mapper
		const auto EnumIndex = static_cast<int64>(CharacterMeshConfig.CustomizationElement);
		const auto Index = Enum->GetIndexByValue(EnumIndex);
		const auto CustomizationElement = Enum->GetNameStringByIndex(Index);

		return FCharacterMeshConfigDTO(CustomizationElement,
		                               CharacterMeshConfig.ActiveElement);
	}

	static FCustomizationConfig MapToCharacterMeshConfig(FCharacterMeshConfigDTO CharacterMeshConfigDTO)
	{
		const ECustomizationElement CustomizationElement =
			Utils::StringToEnum<ECustomizationElement>(CharacterMeshConfigDTO.customElement);

		return FCustomizationConfig(CustomizationElement, CharacterMeshConfigDTO.activeElement);
	}
};
