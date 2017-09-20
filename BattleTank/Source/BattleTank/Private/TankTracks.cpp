// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




void UTankTracks::SetThrottleForward(float Throttle)
{


	FVector ForceApplied = GetForwardVector() * Throttle *TrackMaxDrivingForce; 
	FVector ForcedLocation = GetComponentLocation();
	UPrimitiveComponent* TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRootComponent->AddForceAtLocation(ForceApplied, ForcedLocation, NAME_None);

}
void UTankTracks::SetThrottleSideways(float Throttle)
{


	FVector ForceApplied = GetRightVector() * Throttle *TrackMaxDrivingForce;
	FVector ForcedLocation = GetComponentLocation();
	UPrimitiveComponent* TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRootComponent->AddForceAtLocation(ForceApplied, ForcedLocation, NAME_None);

}
