// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "UI/Widgets/HGBaseView.h"
#include "HGLoginView.generated.h"

UCLASS()
class UHGLoginView : public UHGBaseView
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
	UHGLoginView();

	UFUNCTION()
	void OnClick_Registration();

protected:
	virtual void NativeOnInitialized() override;
};
