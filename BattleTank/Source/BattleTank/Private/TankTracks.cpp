// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




void UTankTracks::SetThrottle(float Throttle)
{
	FString Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: throttle:  %f "), *Name, Throttle);

	FVector ForceApplied = GetForwardVector() * Throttle *TrackMaxDrivingForce; 
	FVector ForcedLocation = GetComponentLocation();
	UPrimitiveComponent* TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRootComponent->AddForceAtLocation(ForceApplied, ForcedLocation, NAME_None);

}
