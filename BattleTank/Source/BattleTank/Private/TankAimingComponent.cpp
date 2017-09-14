// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


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
void UTankAimingComponent::SetBarrel(UStaticMeshComponent* BarrelToSet)
{
	this->Barrel = BarrelToSet;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
void UTankAimingComponent::Logger( FVector OutHitLocation) {
	auto TankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %s is aiming at %s"),*TankName, *OutHitLocation.ToString());

}

