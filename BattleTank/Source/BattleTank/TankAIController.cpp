// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay(){
	Super::BeginPlay();
	Logger();
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank> (GetPawn());
}


void ATankAIController::Logger() {
	ATank* LogTank = GetControlledTank();

	UE_LOG(LogTemp, Warning, TEXT("Tank AI initiated"));

	if (LogTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank AI is: %s"), *LogTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Tank AI"));

	}
}
