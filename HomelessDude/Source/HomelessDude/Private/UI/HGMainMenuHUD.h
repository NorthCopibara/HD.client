// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widgets/HGBaseView.h"
#include "HGMainMenuHUD.generated.h"

UCLASS()
class AHGMainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TArray<TSubclassOf<UHGBaseView>> UserWidgets;
	
private:
	UPROPERTY()
	TMap<EMenuViewName, UHGBaseView*> ViewInstances;

public:
	void Hide(EMenuViewName viewType);
	void Show(EMenuViewName viewType);
	void SetCursor(bool isVisible);

	void InitViews();

protected:
	virtual void BeginPlay() override;

private:
	UUserWidget* GetViewByType(EMenuViewName ViewType);
};
