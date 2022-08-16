#pragma once

#include "Game/View/Characters/Components/HDCustomizationComponent.h"
#include "Network/dto/CharacterDTO.h"
#include "Utils/Utils.h"

class CharacterMeshConfigMapper
{
public:
	static FCharacterMeshConfigDTO MapToCharacterMeshConfigDto(FCustomizationConfig CharacterMeshConfig)
	{
		const auto CustomizationElement = ENUM_VALUE_TO_STRING(ECustomizationElement,
		                                                       CharacterMeshConfig.CustomizationElement);
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
