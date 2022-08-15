// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Game/View/HDGameInstance.h"
#include "UI/Widgets/HDBaseView.h"
#include "HDLoginView.generated.h"

UCLASS()
class UHDLoginView : public UHDBaseView
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UButton* LoginBut;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* Text_Username;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* Text_Password;

public:
	UHDLoginView();

	UFUNCTION()
	void OnClick_Login();

protected:
	virtual void NativeOnInitialized() override;

	//TODO: fix this
private:
	UPROPERTY()
	UHDGameInstance* GameInstance = nullptr;
};
