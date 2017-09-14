// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATank* GetPlayerTank() const;
	ATank* GetControlledTank() const;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void Logger();
};
