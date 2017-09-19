// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));


}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}
void ATank::SetTurrentReference(UTankTurrent* TurrentToSet)
{
	TankAimingComponent->SetTurrentReference(TurrentToSet);
}
void ATank::AimAt(FVector OutHitLocation)
{
	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}
 void ATank::Fire() {
	 if (!Barrel)
	 {
		 return;
	 }
	 else {


		 auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			 ProjectileBlueprint,
			 Barrel->GetSocketLocation(FName("Projectile")),
			 Barrel->GetSocketRotation(FName("Projectile")));

		 Projectile->LaunchProjectile(LaunchSpeed);
	 }

} 