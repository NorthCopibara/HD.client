// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UI/Widgets/HGBaseView.h"
#include "HGMainMenuView.generated.h"

UCLASS()
class UHGMainMenuView : public UHGBaseView
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UButton* LoginBut;

	UPROPERTY(meta = (BindWidget))
	UButton* RegistrationBut;

public:
	UHGMainMenuView();

	UFUNCTION()
	void OnClick_MoveToLogin();

	UFUNCTION()
	void OnClick_MoveToRegistration();
	
protected:
	virtual void NativeOnInitialized() override;
};
