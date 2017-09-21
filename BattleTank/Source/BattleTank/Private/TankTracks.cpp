// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTracks.h"



void UTankTracks::SetThrottle(float Throttle)
{
	// TODO clamp actual throttle value so player can't over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
void UTankTracks::SetThrottleSideways(float Throttle)
{


	FVector ForceApplied = GetRightVector() * Throttle *TrackMaxDrivingForce;
	FVector ForcedLocation = GetComponentLocation();
	UPrimitiveComponent* TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRootComponent->AddForceAtLocation(ForceApplied, ForcedLocation, NAME_None);

}
