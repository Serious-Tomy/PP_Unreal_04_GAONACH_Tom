// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FlagManager.h"
#include "Rattrapage_CPP_BPGameMode.generated.h"

/**
 *  Simple GameMode for a first person game
 */
UCLASS()
class ARattrapage_CPP_BPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARattrapage_CPP_BPGameMode();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFlagManager* FlagManager;

	UFUNCTION(BlueprintCallable)
	int GetKills();

	UFUNCTION(BlueprintCallable)
	void IncrementKills();
};



