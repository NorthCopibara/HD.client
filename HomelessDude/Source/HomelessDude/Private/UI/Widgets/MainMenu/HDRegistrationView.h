// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "UI/Widgets/HDBaseView.h"
#include "HDRegistrationView.generated.h"

UCLASS()
class UHDRegistrationView : public UHDBaseView
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UButton* RegistrationBut;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* Text_Username;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* Text_Password;

public:
	UHDRegistrationView();

	UFUNCTION()
	void OnClick_Registration();

protected:
	virtual void NativeOnInitialized() override;
};