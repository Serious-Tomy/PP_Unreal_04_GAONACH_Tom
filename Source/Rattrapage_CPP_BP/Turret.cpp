// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "FlagManager.h"
#include "GameplayTagContainer.h"
#include "GameFramework/GameModeBase.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += DeltaTime;

	if (Timer >= 1.0f)
	{
		Shoot();
		Timer -= 1.0f;
	}

}


void ATurret::TakeDamage_Implementation(int amount)
{
	if (amount >= TurretHealth)
	{
		if (AGameModeBase* GM = GetWorld()->GetAuthGameMode())
		{
			if (UFlagManager* FM = GM->FindComponentByClass<UFlagManager>())
			{
				FM->IncrementFlag(FGameplayTag::RequestGameplayTag(FName("Kills")));
			}
		}

		Destroy();
	}
}

void ATurret::Shoot()
{
	FHitResult Hit;
	ECollisionChannel Channel(ECC_GameTraceChannel1);
	FVector Starting = Canon->GetComponentLocation();
	FVector End = Starting + Canon->GetForwardVector() * 300.0f;
	const FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	if (GetWorld()->LineTraceSingleByChannel(OUT Hit, Starting, End, Channel, TraceParams))
	{
		AActor* HitActor = Hit.GetActor();

		if (HitActor == nullptr)
			return;

		if (HitActor->Implements<UHealth>())
			IHealth::Execute_TakeDamage(HitActor, Damage);
	}
}
