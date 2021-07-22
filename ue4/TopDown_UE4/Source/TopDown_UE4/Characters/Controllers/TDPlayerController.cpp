// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"
#include "Characters/TDBaseCharacter.h"

void ATDPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<ATDBaseCharacter>(InPawn);
}

ATDPlayerController::ATDPlayerController()
{
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATDPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATDPlayerController::MoveRight);
	InputComponent->BindAxis("LookUp", this, &ATDPlayerController::LookUp);
	InputComponent->BindAxis("LookRight", this, &ATDPlayerController::LookRight);
	InputComponent->BindAxis("MouseUp", this, &ATDPlayerController::MouseUp);
	InputComponent->BindAxis("MouseRight", this, &ATDPlayerController::MouseRight);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATDPlayerController::Jump);
}

void ATDPlayerController::MoveForward(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForward(Value);
	}
}

void ATDPlayerController::MoveRight(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRight(Value);
	}
}

void ATDPlayerController::LookRight(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookRight(Value);
	}
}

void ATDPlayerController::LookUp(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUp(Value);
	}
}

void ATDPlayerController::MouseUp(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MouseUp(Value);
	}
}

void ATDPlayerController::MouseRight(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MouseRight(Value);
	}
}

void ATDPlayerController::Jump()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}
