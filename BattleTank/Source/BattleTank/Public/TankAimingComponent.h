// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward Declaration
class UTankBarrel; 
class UTankTurrent;

//Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector OutHitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurrentReference(UTankTurrent* TurrentToSet);
	UTankBarrel* GetBarrelComponent() const;
	UTankTurrent* GetTurrentComponent() const;


protected:
	virtual void BeginPlay() override;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;
	void MoveBarrelTo(FVector AimTarget);
};
