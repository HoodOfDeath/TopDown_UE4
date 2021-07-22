// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

APlayerCharacter::APlayerCharacter()
{
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true);
	SpringArmComponent->TargetArmLength = 800.f;
	SpringArmComponent->SetRelativeRotation(FRotator(-80.f, 0.0f, 0.0f));
	SpringArmComponent->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

void APlayerCharacter::MoveForward(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1E-6f))
	{
		//FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		//FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(FVector::ForwardVector, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1E-6f))
	{
		//FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		//FVector RightVector = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(FVector::RightVector, Value);
	}
}

void APlayerCharacter::LookUp(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	{
		LookDirection.X = Value;
	}
}

void APlayerCharacter::LookRight(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	{
		LookDirection.Y = Value;
	}
}

void APlayerCharacter::MouseUp(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	{
		MouseShift.Y = Value;
	}
}

void APlayerCharacter::MouseRight(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	{
		MouseShift.X = Value;
	}
}

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UE_LOG(LogTemp, Log, TEXT("MouseShift %s"), *MouseShift.ToString())
	
	if (LookDirection != FVector::ZeroVector)
	{
		SetActorRotation(LookDirection.Rotation());
	}
	else if (MouseShift != FVector::ZeroVector)
	{
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			float x, y;

			PC->GetMousePosition(x, y);

			FVector2D MousePos(x, y);

			FVector2D Viewport(1, 1);

			if (GEngine && GEngine->GameViewport)
			{
				GEngine->GameViewport->GetViewportSize(/*out*/Viewport);
			}

			FVector2D Result((Viewport - MousePos) - Viewport * 0.5f);
			FVector Res(Result.Y, -Result.X, 0);

			SetActorRotation(Res.Rotation());
		}
	}

	LookDirection = FVector::ZeroVector;
	MouseShift = FVector::ZeroVector;
}
