// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay(){
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true; //We won't be ticked by default  
	Logger();
	
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const {

	return  Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetControlledTank()) {
		ATank* AiTank = GetControlledTank();
		if (GetPlayerTank()) {
			AiTank->AimAt(GetPlayerTank()->GetActorLocation());
		}
	}

}

void ATankAIController::Logger() {
	ATank* LogTank = GetControlledTank();
	ATank* PlayerTank =GetPlayerTank();

	UE_LOG(LogTemp, Warning, TEXT("Tank AI initiated"));

	if (LogTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank AI is: %s"), *LogTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Tank AI"));

	}
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Player is: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"));

	}
}
