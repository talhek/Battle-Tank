// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
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
	if (!BarrelToSet)
	{
		return;
	}
	this->Barrel = BarrelToSet;
}
UTankBarrel* UTankAimingComponent::GetBarrelComponent() const
{
	return this->Barrel;
}
void UTankAimingComponent::SetTurrentReference(UTankTurrent* TurrentToSet)
{
	if (!TurrentToSet)
	{
		return;
	}
	this->Turrent = TurrentToSet;
}
UTankTurrent* UTankAimingComponent::GetTurrentComponent() const
{
	return this->Turrent;
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);
	}

}
void UTankAimingComponent::MoveBarrelTo(FVector AimTarget)
{

	//auto BarrelRotator = (Barrel->GetRightVector()).Rotation();
	FRotator BarrelRotator = (GetBarrelComponent()->GetForwardVector()).Rotation();
	FRotator AimAsRotator = AimTarget.Rotation();
	FRotator DeltaRotator = AimAsRotator -BarrelRotator ;

	this->Barrel->Elevate(DeltaRotator.Pitch); 
	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		Turrent->Rotate(DeltaRotator.Yaw);
	}
	else // Avoid going the long-way round
	{
		Turrent->Rotate(-DeltaRotator.Yaw);
	}

}
