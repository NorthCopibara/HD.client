// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widgets/HDBaseView.h"
#include "HDMainMenuHUD.generated.h"

UCLASS()
class AHDMainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TArray<TSubclassOf<UHDBaseView>> UserWidgets;
	
private:
	UPROPERTY()
	TMap<EMenuViewName, UHDBaseView*> ViewInstances;

public:
	void Hide(EMenuViewName viewType);
	void Show(EMenuViewName viewType);
	void Revert(EMenuViewName viewType);
	void SetCursor(bool isVisible);

	void InitViews();

protected:
	virtual void BeginPlay() override;

private:
	UUserWidget* GetViewByType(EMenuViewName ViewType);
};
