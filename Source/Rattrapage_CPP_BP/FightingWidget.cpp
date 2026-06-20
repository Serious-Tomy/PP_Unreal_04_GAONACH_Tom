// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingWidget.h"

void UFightingWidget::SetEndText(FString Text)
{
    if (!EndText) return;
	EndText->SetText(FText::FromString(Text));
}

void UFightingWidget::SetHealth(float Ratio)
{
    if (!Health) return;
	Health->SetPercent(Ratio);
}

void UFightingWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (EndText) EndText->SetVisibility(ESlateVisibility::Hidden);
    if (Health) Health->SetPercent(1.0f);
}