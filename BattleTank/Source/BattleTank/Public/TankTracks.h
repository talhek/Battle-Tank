// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * TankTrack is used to set max driving force, and to apply forces to the tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//sets a throttle between -1 to +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);
	
	//Max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000; //Assume 40 tonne tank and 1g acceleration 
	
	
};
