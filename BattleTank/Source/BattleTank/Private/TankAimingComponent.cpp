// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "Engine/World.h" //<-- needed for GetOwner()! UE:4.17.1
#include "Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO should this really tick?

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	this->Barrel = BarrelToSet;
}
UTankBarrel* UTankAimingComponent::GetBarrelComponent() const
{
	return this->Barrel;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
void UTankAimingComponent::MoveBarrelTo(FVector AimTarget)
{
	//TODO need to work out difference between starting position and target position,
	FRotator BarrelRotator = this->Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimTarget.Rotation();
	FRotator DeltaRotator = BarrelRotator - AimAsRotator;

	this->Barrel->Elevate(5); //TODO remove magic number
}

void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed) {
	auto TankName = GetOwner()->GetName();
	//auto BarrelLocation = GetBarrelComponent()->GetComponentLocation().ToString();
	if (!GetBarrelComponent())
		return;
	FVector OutLaunchVelocity = FVector();
	FVector StartLocation = this->Barrel->GetSocketLocation(FName("Projectile"));
	bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bAimSolution) {
		// Calculate the OutLaunchVelocity
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);
	}
	else {
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution NOT found"), Time);
	}

}

