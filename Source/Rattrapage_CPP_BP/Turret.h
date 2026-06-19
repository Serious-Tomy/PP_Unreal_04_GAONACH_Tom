// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Health.h"
#include "Turret.generated.h"


UCLASS()
class RATTRAPAGE_CPP_BP_API ATurret : public AActor, public IHealth
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Canon;


	UPROPERTY(EditAnywhere)
	int TurretHealth = 10;

	void TakeDamage_Implementation(int amount);

	void Shoot();

	int Damage;

	float Timer;
};
