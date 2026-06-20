// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include <Components/ProgressBar.h>
#include "FightingWidget.generated.h"

/**
 * 
 */
UCLASS()
class RATTRAPAGE_CPP_BP_API UFightingWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetEndText(FString Text);
	UFUNCTION(BlueprintCallable)
	void SetHealth(float Ratio);

public:
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	UTextBlock* EndText;
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	UProgressBar* Health;

protected:
    virtual void NativeConstruct() override;
};
