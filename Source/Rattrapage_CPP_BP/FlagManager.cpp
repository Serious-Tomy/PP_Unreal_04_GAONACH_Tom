// Fill out your copyright notice in the Description page of Project Settings.


#include "FlagManager.h"

// Sets default values for this component's properties
UFlagManager::UFlagManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFlagManager::BeginPlay()
{
	Super::BeginPlay();

	FGameplayTag KillsTag = FGameplayTag::RequestGameplayTag(FName("Kills"));

	if (!Flags.Contains(KillsTag))
	{
		Flags.Add(KillsTag, 0);
	}

}

void UFlagManager::IncrementFlag(FGameplayTag Tag)
{
	if (int* Value = Flags.Find(Tag))
	{
		(*Value)++;
	}
}

int UFlagManager::GetFlagValue(FGameplayTag Tag) const
{
	const int* Value = Flags.Find(Tag);
	return Value ? *Value : 0;
}

// Called every frame
void UFlagManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

