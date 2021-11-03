// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TDBaseCharacter.h"
#include "PlayerCharacter.generated.h"

class ATDProjectile;
UCLASS()
class TOPDOWN_UE4_API APlayerCharacter : public ATDBaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	virtual void BeginPlay() override;

	virtual void MoveForward(float Value) override;
	virtual void MoveRight(float Value) override;
	virtual void MoveForwardStick(float Value) override;
	virtual void MoveRightStick(float Value) override;
	virtual void LookUp(float Value) override;
	virtual void LookRight(float Value) override;
	virtual void MouseUp(float Value) override;
	virtual void MouseRight(float Value) override;

	virtual void StartFiring() override;
	virtual void StopFiring() override;

	virtual void HoldDash() override;
	virtual void ReleaseDash() override;

	virtual void HoldChargedShot() override;
	virtual void ReleaseChargedShot() override;

	virtual void Parry() override;

	virtual void HoldSlash() override;
	virtual void ReleaseSlash() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character|Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character|Camera")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character|Shooting")
	TSubclassOf<ATDProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USceneComponent* MuzzlePoint;

	/*Fire rate in rounds per minute*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Shooting")
	float FireRate = 450.0f;

	virtual void Tick(float DeltaSeconds) override;

private:
	FVector LookDirection = FVector::ZeroVector;
	FVector MouseShift = FVector::ZeroVector;

	bool bIntendToShoot = false;
	bool bIsShotReady = true;

	float DelayBetweenShots;

	void Fire();
	bool CanFire();
	void SetShotReady() { bIsShotReady = true; }

	FTimerHandle FiringDelay;
};
