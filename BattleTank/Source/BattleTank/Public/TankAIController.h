// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
/**
 * 
 */
class ATank;

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

	UPROPERTY(EditDefaultsOnly, Category = Paths)
	float AcceptanceRadius = 3000.0f;


};
