// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TDBaseCharacter.generated.h"

UCLASS()
class TOPDOWN_UE4_API ATDBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATDBaseCharacter();

	virtual void MoveForward(float Value)
	{
	};

	virtual void MoveRight(float Value)
	{
	};

	virtual void LookUp(float Value)
	{
	};
	
	virtual void LookRight(float Value)
	{
	};
	
	virtual void MouseUp(float Value)
	{
	};
	
	virtual void MouseRight(float Value)
	{
	};

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character|Controls")
	float BaseTurnRate = 45.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character|Controls")
	float BaseLookUpRate = 45.0f;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
