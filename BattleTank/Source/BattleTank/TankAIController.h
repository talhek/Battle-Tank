// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	auto* GetPlayerTank() const;
	auto* GetControlledTank() const;
protected:
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

private:
	void Logger();
	/*
	//Start the tank moving the barrel so that a shot would hit
	//where the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector & OutHitLocation) const;
	*/
};
