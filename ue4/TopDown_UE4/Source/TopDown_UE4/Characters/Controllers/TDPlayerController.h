// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

class UPlayerHUDWidget;

UCLASS()
class TOPDOWN_UE4_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

	ATDPlayerController();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UPlayerHUDWidget> PlayerHUDWidgetClass;
	
	virtual void SetupInputComponent() override;

private:
	TSoftObjectPtr<class ATDBaseCharacter> CachedBaseCharacter;
	UPlayerHUDWidget* PlayerHUDWidget = nullptr;

	void CreateAndInitializeWidgets();

	//1) Movement
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveForwardStick(float Value);
	void MoveRightStick(float Value);

	//2) Shooting
	void LookUp(float Value);
	void LookRight(float Value);
	void MouseUp(float Value);
	void MouseRight(float Value);
	
	void HoldFire();
	void ReleaseFire();

	//3) Dash
	void HoldDash();
	void ReleaseDash();
	
	//4) Charged shot
	void HoldChargedShot();
	void ReleaseChargedShot();

	//5) Parry
	void Parry();

	//6/7) Melee slash / charged slash
	void HoldSlash();
	void ReleaseSlash();
	
	void Jump();

	
};
