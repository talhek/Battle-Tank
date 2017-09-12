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