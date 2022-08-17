// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/View/GameModes/HDMainMenuGameMode.h"

#include "JsonObjectConverter.h"
#include "Game/View/HDGameInstance.h"
#include "Game/View/Characters/Components/HDCustomizationComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Network/dto/CharacterDTO.h"
#include "Network/dto/SelectionMenuDTO.h"
#include "Network/Mappers/CharacterMapper.h"
#include "Network/Requests/GetSelectionCharacterRequest.h"
#include "UI/HDMainMenuHUD.h"

AHDMainMenuGameMode::AHDMainMenuGameMode()
{
	HUDClass = AHDMainMenuGameMode::StaticClass();
}

void AHDMainMenuGameMode::LoadPlayerCharacters()
{
	const auto Hud = Cast<AHDMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (!Hud) return;

	Hud->Hide(EMenuViewName::Login);

	const auto GameInstance = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("Game instance not found"))
		return;
	}

	UE_LOG(LogTemp, Error, TEXT("Token: %s"), *GameInstance->GetAuthToken())

	GetSelectionCharacterRequest::Send(GameInstance->GetAuthToken(), [&](FHttpRequestPtr Request,
	                                                                     FHttpResponsePtr Response,
	                                                                     bool bWasSuccessful)
	{
		if (!HttpService::ResponseIsValid(Response, bWasSuccessful))
		{
			UE_LOG(LogTemp, Error, TEXT("Get selection character request faild"))
			UE_LOG(LogTemp, Error, TEXT("Response message: %s"), *Response->GetContentAsString())
			return;
		};


		FSelectionMenuDTO SelectionMenuDto;
		const FString JsonString = Response->GetContentAsString();

		FJsonObjectConverter::JsonObjectStringToUStruct<FSelectionMenuDTO>(JsonString, &SelectionMenuDto, 0, 0);

		for (const auto CharacterDTO : SelectionMenuDto.charactersDTO)
		{
			PlayerCharacters.Add(CharacterMapper::MapToCharacterModel(CharacterDTO));
		}

		const auto CustomizationComponent = GetCustomizationComponent();
		if (!CustomizationComponent) return;

		for (int32 i = 0; i < PlayerCharacters.Num(); i++)
		{
			if (PlayerCharacters[i].IsSelected)
			{
				CustomizationComponent->RefreshMeshes(PlayerCharacters[i].MeshConfigs);
				SelectedPlayerCharacterId = i;
				break;
			}
		}

		//TODO: create transitions
		const auto InternalHud = Cast<AHDMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		if (!InternalHud) return;

		InternalHud->Show(EMenuViewName::SelectCharacter);
		InternalHud->Revert(EMenuViewName::SelectCharacter);
	});
}

void AHDMainMenuGameMode::NextPlayerCharacter()
{
	if (GetCountCharacters() < 2) return;
	
	int32 NextId = SelectedPlayerCharacterId + 1;
	if (NextId >= PlayerCharacters.Num())
	{
		NextId = 0;
	}

	const auto CustomizationComponent = GetCustomizationComponent();
	if (!CustomizationComponent) return;
	CustomizationComponent->RefreshMeshes(PlayerCharacters[NextId].MeshConfigs);

	SelectedPlayerCharacterId = NextId;
}

void AHDMainMenuGameMode::PreviousPlayerCharacter()
{
	if (GetCountCharacters() < 2) return;

	int32 NextId = SelectedPlayerCharacterId - 1;
	if (NextId < 0)
	{
		NextId = PlayerCharacters.Num() - 1;
	}

	const auto CustomizationComponent = GetCustomizationComponent();
	if (!CustomizationComponent) return;
	CustomizationComponent->RefreshMeshes(PlayerCharacters[NextId].MeshConfigs);

	SelectedPlayerCharacterId = NextId;
}

FString AHDMainMenuGameMode::GetSelectedCharacterName()
{
	if (!PlayerCharacters.IsValidIndex(SelectedPlayerCharacterId)) return FString{};
	return PlayerCharacters[SelectedPlayerCharacterId].Name;
}

int32 AHDMainMenuGameMode::GetCountCharacters() const
{
	return PlayerCharacters.Num();
}

UHDCustomizationComponent* AHDMainMenuGameMode::GetCustomizationComponent()
{
	const auto CustomizationPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!CustomizationPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("Customization pawn not found"))
		return nullptr;
	}

	const auto CustomizationComponent =
		Cast<UHDCustomizationComponent>(
			CustomizationPawn->GetComponentByClass(UHDCustomizationComponent::StaticClass()));
	if (!CustomizationComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Customization component not found!"))
		return nullptr;
	}

	return CustomizationComponent;
}
