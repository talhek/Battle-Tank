// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	//Logger();
}
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {
		return;
	}
	FVector OutHitLocation;

	if (GetSightRayHitLocation(OutHitLocation)) {
		GetControlledTank()->AimAt(OutHitLocation);

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	FVector LookDirection;

	//Find the crosshair position
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX* CrossHairXLocation, ViewportSizeY* CrossHairYLocation);

	//De-project the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//Line-trace along that look direction, and see what we hit(up to max range)
		if (GetLookPlayerHitLocation(LookDirection, OutHitLocation)){}
	}
	return true;
}
bool ATankPlayerController::GetLookPlayerHitLocation(FVector LookDirection, FVector& OutHitLocation) const{
	FHitResult HitResult = FHitResult();
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);


	if (GetWorld()->LineTraceSingleByChannel(HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) {

		OutHitLocation = HitResult.Location;
		return true;
	}
	else {
		OutHitLocation = FVector(0.f);
		return false;
	}

}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraLookDirection; //to be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLookDirection, LookDirection);

}
void ATankPlayerController::Logger() {
	ATank *LogTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController initiated"));
	if (LogTank) {
		UE_LOG(LogTemp, Warning, TEXT("The Tank is: %s"), *(LogTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Tank is available"));
	}
}