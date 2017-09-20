// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Public/TankTracks.h"




void UTankMovementComponent::Initialize(UTankTracks *RightTrack, UTankTracks* LeftTrack)
{
	if ((!RightTrack) || (!LeftTrack)) {
		return;
	}
	this->LeftTrack = LeftTrack;
	this->RightTrack = RightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	RightTrack->SetThrottleForward(Throw);
	LeftTrack->SetThrottleForward(Throw);
	UE_LOG(LogTemp, Warning, TEXT("MovementForward throw: %f "), Throw);
}
void UTankMovementComponent::IntendMoveSideways(float Throw)
{
	RightTrack->SetThrottleSideways(Throw);
	LeftTrack->SetThrottleSideways(Throw);
	UE_LOG(LogTemp, Warning, TEXT("MovementForward throw: %f "), Throw);
}
