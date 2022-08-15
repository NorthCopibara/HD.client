// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "UI/Widgets/HDBaseView.h"
#include "HDSelectCharacterView.generated.h"

UCLASS()
class HOMELESSDUDE_API UHDSelectCharacterView : public UHDBaseView
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CharName;

	UPROPERTY(meta = (BindWidget))
	UButton* Select;
	
	UPROPERTY(meta = (BindWidget))
	UButton* CreateChar;

	UPROPERTY(meta = (BindWidget))
	UButton* NextChar;

	UPROPERTY(meta = (BindWidget))
	UButton* PreviousChar;

public:
	UHDSelectCharacterView();
	
protected:
	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnClick_Select();

	UFUNCTION()
	void OnClick_CreateChar();

	UFUNCTION()
	void OnClick_NextChar();

	UFUNCTION()
	void OnClick_PreviousChar();
};
