// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay(){
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true; //We won't be ticked by default  
	Logger();
	
}

auto* ATankAIController::GetControlledTank() const {
	return GetPawn();
}
auto* ATankAIController::GetPlayerTank() const {
	//auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	//if (PlayerTank)
	//	return (PlayerTank);
	return GetWorld()->GetFirstPlayerController()->GetPawn();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}
void ATankAIController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {
		return;
	}
	FVector OutHitLocation = FVector();
	if (GetSightRayHitLocation(OutHitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *OutHitLocation.ToString());
		//Get world location of lintrace hits the landscape
		//TODO tell controlled tank to aim at this point
	}
}

bool ATankAIController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}



void ATankAIController::Logger() {
	ATank* LogTank = Cast<ATank>(GetControlledTank());
	ATank* PlayerTank = Cast<ATank>(GetPlayerTank());

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
