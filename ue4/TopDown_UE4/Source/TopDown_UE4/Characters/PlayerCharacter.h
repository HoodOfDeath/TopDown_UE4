// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TDBaseCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TOPDOWN_UE4_API APlayerCharacter : public ATDBaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();
	
	virtual void MoveForward(float Value) override;
	virtual void MoveRight(float Value) override;
	virtual void MoveForwardStick(float Value) override;
	virtual void MoveRightStick(float Value) override;
	virtual void LookUp(float Value) override;
	virtual void LookRight(float Value) override;
	virtual void MouseUp(float Value) override;
	virtual void MouseRight(float Value) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Character|Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Character|Camera")
	class USpringArmComponent* SpringArmComponent;

	virtual void Tick(float DeltaSeconds) override;

private:
	FVector LookDirection = FVector::ZeroVector;
	FVector MouseShift = FVector::ZeroVector;
};
