// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	// returns pointer to Tank object
	ATank* GetControlledTank() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void Logger();
};
