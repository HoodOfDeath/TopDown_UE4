// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_UE4_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

	ATDPlayerController();

protected:
	virtual void SetupInputComponent() override;

private:
	TSoftObjectPtr<class ATDBaseCharacter> CachedBaseCharacter;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUp(float Value);
	void LookRight(float Value);
	void MouseUp(float Value);
	void MouseRight(float Value);
	void Jump();
};
