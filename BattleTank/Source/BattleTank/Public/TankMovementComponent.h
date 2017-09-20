// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;
/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTankTracks *RightTrack, UTankTracks* LeftTrack);
	UFUNCTION(BlueprintCallable, Category = Throtting)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Throtting)
		void IntendMoveSideways(float Throw);

private:
	
	UTankTracks* RightTrack = nullptr;
	UTankTracks* LeftTrack = nullptr;
	
};
