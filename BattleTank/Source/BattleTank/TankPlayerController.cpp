// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	Logger();
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
	FVector OutHitLocation = FVector();
	if (GetSightRayHitLocation(OutHitLocation)) {
	//	UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
		//Get world location of lintrace hits the landscape
		//TODO tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX* CrossHairXLocation, ViewportSizeY* CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *ScreenLocation.ToString());

	//De-project the screen position of the crosshair to a world direction
	//Line-trace along that look direction, and see what we hit(up to max range)


	return true;
}
void ATankPlayerController::Logger() {
	auto *LogTank = GetControlledTank();

	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController initiated"));
	
	if (LogTank) {
		UE_LOG(LogTemp, Warning, TEXT("The Tank is: %s"), *(LogTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Tank is available"));

	}
}