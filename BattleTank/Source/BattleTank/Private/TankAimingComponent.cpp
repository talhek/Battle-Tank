// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	this->Barrel = BarrelToSet;
}
UStaticMeshComponent* UTankAimingComponent::GetBarrelComponent() const
{
	return this->Barrel;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
void UTankAimingComponent::AimAt( FVector OutHitLocation, float LaunchSpeed) {
	//auto TankName = GetOwner()->GetName();
	//auto BarrelLocation = GetBarrelComponent()->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT(" Firing at launch speed: %f"), LaunchSpeed);

}

