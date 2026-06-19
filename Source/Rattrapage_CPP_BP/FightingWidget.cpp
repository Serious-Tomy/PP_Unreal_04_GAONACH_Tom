// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingWidget.h"

void UFightingWidget::SetEndText(FString Text)
{
	EndText->SetText(FText::FromString(Text));
}

void UFightingWidget::SetHealth(float Ratio)
{
	Health->SetPercent(Ratio);
}