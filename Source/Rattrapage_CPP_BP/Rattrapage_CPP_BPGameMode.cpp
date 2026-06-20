// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rattrapage_CPP_BPGameMode.h"
#include "FlagManager.h"

ARattrapage_CPP_BPGameMode::ARattrapage_CPP_BPGameMode()
{
	// stub
}


int ARattrapage_CPP_BPGameMode::GetKills()
{
    if (FlagManager)
    {
        return FlagManager->GetFlagValue(
            FGameplayTag::RequestGameplayTag(FName("Kills"))
        );
    }
    return 0;
}

void ARattrapage_CPP_BPGameMode::IncrementKills()
{
    if (FlagManager)
    {
        FlagManager->IncrementFlag(
            FGameplayTag::RequestGameplayTag(FName("Kills"))
        );
    }
}