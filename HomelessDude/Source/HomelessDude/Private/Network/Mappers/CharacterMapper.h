#pragma once
#include "CharacterMeshConfigMapper.h"
#include "Game/View/Characters/Components/HDCustomizationComponent.h"
#include "Network/dto/CharacterDTO.h"
#include "Network/Models/CharacterModel.h"

class CharacterMapper
{
public:
	static FCharacterDTO MapToCharacterDTO(FCharacterModel Character)
	{
		TArray<FCharacterMeshConfigDTO> CharacterMeshConfigsDTO;

		for (const auto MeshConfig : Character.MeshConfigs)
		{
			CharacterMeshConfigsDTO.Add(CharacterMeshConfigMapper::MapToCharacterMeshConfigDto(MeshConfig));
		}
		
		return FCharacterDTO(Character.Name,
		                     Character.IsSelected,
		                     CharacterMeshConfigsDTO);
	}

	static FCharacterModel MapToCharacterModel(FCharacterDTO CharacterDTO)
	{
		TArray<FCustomizationConfig> CharacterMeshConfigs;

		for (const auto MeshConfig : CharacterDTO.CharacterMeshConfigsDTO)
		{
			CharacterMeshConfigs.Add(CharacterMeshConfigMapper::MapToCharacterMeshConfig(MeshConfig));
		}

		return FCharacterModel(CharacterDTO.name, CharacterMeshConfigs, CharacterDTO.isSelected);
	}
};
