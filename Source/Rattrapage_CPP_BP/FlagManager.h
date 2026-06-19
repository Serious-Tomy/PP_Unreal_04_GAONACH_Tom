// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FlagManager.generated.h"


UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RATTRAPAGE_CPP_BP_API UFlagManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlagManager();

	TMap<FGameplayTag, int> Flags;

	UFUNCTION(BlueprintCallable)
	void IncrementFlag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetFlagValue(FGameplayTag Tag) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
