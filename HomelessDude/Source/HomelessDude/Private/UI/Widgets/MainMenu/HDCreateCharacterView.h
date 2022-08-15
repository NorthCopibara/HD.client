// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Game/View/Characters/HDCustomizationActor.h"
#include "UI/Widgets/HDBaseView.h"
#include "HDCreateCharacterView.generated.h"


UCLASS()
class HOMELESSDUDE_API UHDCreateCharacterView : public UHDBaseView
{
	GENERATED_BODY()

	//TODO: refactor this
public:
	UPROPERTY(meta = (BindWidget))
	UButton* Legs_1;

	UPROPERTY(meta = (BindWidget))
	UButton* Legs_2;

	UPROPERTY(meta = (BindWidget))
	UButton* Body_1;

	UPROPERTY(meta = (BindWidget))
	UButton* Body_2;

	UPROPERTY(meta = (BindWidget))
	UButton* Body_3;

	UPROPERTY(meta = (BindWidget))
	UButton* Beard_1;

	UPROPERTY(meta = (BindWidget))
	UButton* Beard_2;

	UPROPERTY(meta = (BindWidget))
	UButton* Hair_1;

	UPROPERTY(meta = (BindWidget))
	UButton* Hair_2;

	UPROPERTY(meta = (BindWidget))
	UButton* Hair_3;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* CharName;

	UPROPERTY(meta = (BindWidget))
	UButton* Create;

	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "View")
	TSubclassOf<AHDCustomizationActor> CustomizationActorPref;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "View")
	FVector SpawnPoint;

private:
	TMap<ECustomizationElement, FCustomizationConfig> CustomizationConfigs;

	UPROPERTY()
	UHDCustomizationComponent* CustomizationComponent = nullptr;

public:
	UHDCreateCharacterView();
	
protected:
	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnClick_Legs_1();

	UFUNCTION()
	void OnClick_Legs_2();

	UFUNCTION()
	void OnClick_Body_1();

	UFUNCTION()
	void OnClick_Body_2();

	UFUNCTION()
	void OnClick_Body_3();

	UFUNCTION()
	void OnClick_Beard_1();

	UFUNCTION()
	void OnClick_Beard_2();

	UFUNCTION()
	void OnClick_Hair_1();

	UFUNCTION()
	void OnClick_Hair_2();

	UFUNCTION()
	void OnClick_Hair_3();

	UFUNCTION()
	void OnClick_Create();

	void UpdateCharacter();
};
