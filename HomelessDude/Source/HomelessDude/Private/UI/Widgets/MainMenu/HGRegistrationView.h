// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "UI/Widgets/HGBaseView.h"
#include "HGRegistrationView.generated.h"

UCLASS()
class UHGRegistrationView : public UHGBaseView
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
	UHGRegistrationView();

	UFUNCTION()
	void OnClick_Registration();

protected:
	virtual void NativeOnInitialized() override;
};
