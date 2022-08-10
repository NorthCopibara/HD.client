// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HGBaseView.generated.h"

UENUM()
enum class EMenuViewName
{
	Default,
	Main,
	Login,
	Registration
};

UCLASS()
class HOMELESSDUDE_API UHGBaseView : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	EMenuViewName ViewName;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	virtual void Close() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	virtual void Init();
	
	UFUNCTION(BlueprintCallable, Category = "UI")
	virtual void Revert();

	EMenuViewName GetViewName() const { return ViewName; }
};
