// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "DrawDebugHelpers.h"
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
		AddMovementInput(FVector::ForwardVector, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1E-6f))
	{
		AddMovementInput(FVector::RightVector, Value);
	}
}

void APlayerCharacter::MoveForwardStick(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1E-6f))
	{
		FQuat Rot = FQuat::MakeFromEuler(FVector::UpVector * -29);
		AddMovementInput(Rot * FVector::ForwardVector, Value);
	}
}

void APlayerCharacter::MoveRightStick(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1E-6f))
	{
		FQuat Rot = FQuat::MakeFromEuler(FVector::UpVector * -29);
		AddMovementInput(Rot * FVector::RightVector, Value);
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

	if (LookDirection != FVector::ZeroVector)
	{
		FQuat Rot = FQuat::MakeFromEuler(FVector::UpVector * -29);
		SetActorRotation((Rot * LookDirection).Rotation());
		LookDirection.Y *= (250 - 23 * LookDirection.X);
		LookDirection.X *= 180;
		LookDirection = Rot * LookDirection;

		SpringArmComponent->TargetOffset = FMath::VInterpTo(SpringArmComponent->TargetOffset, LookDirection, DeltaSeconds, 3.f);
	}
	else if (MouseShift != FVector::ZeroVector)
	{
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FVector MousePositionInWorld, MouseDirection;
			FVector Res;
			if (PC->DeprojectMousePositionToWorld(MousePositionInWorld, MouseDirection))
			{
				FVector PlayerLocation = GetActorLocation();
				FVector Proj = FMath::LinePlaneIntersection(MousePositionInWorld, MousePositionInWorld + MouseDirection, PlayerLocation, FVector::UpVector);

				Res = Proj - PlayerLocation;
				Res.Z = 0;

				FVector2D MousePosOnScreen(0, 0);
				PC->GetMousePosition(MousePosOnScreen.X, MousePosOnScreen.Y);

				FVector2D Viewport(1, 1);
				if (GEngine && GEngine->GameViewport)
				{
					GEngine->GameViewport->GetViewportSize(/*out*/Viewport);
				}

				FVector2D Result((Viewport - MousePosOnScreen) - Viewport * 0.5f);
				Result.X /= (Viewport.X * 0.5f);
				Result.Y /= (Viewport.Y * 0.5f);
				Result.X *= (250 - 23 * Result.Y);
				Result.Y *= 180;
				FVector Tmp = FVector(Result.Y, -Result.X, 0);
				FQuat Rot = FQuat::MakeFromEuler(FVector::UpVector * -29);
				Tmp = Rot * Tmp;

				SpringArmComponent->TargetOffset = Tmp;
			}
			else
			{
				FVector2D MousePosOnScreen(0, 0);

				PC->GetMousePosition(MousePosOnScreen.X, MousePosOnScreen.Y);

				FVector2D Viewport(1, 1);

				if (GEngine && GEngine->GameViewport)
				{
					GEngine->GameViewport->GetViewportSize(/*out*/Viewport);
				}

				FVector2D Result((Viewport - MousePosOnScreen) - Viewport * 0.5f);
				Res = FVector(Result.Y, -Result.X, 0);
			}


			SetActorRotation(Res.Rotation());
		}
	}

	FVector LineStart = GetActorLocation();
	FVector LineEnd = LineStart + GetActorForwardVector() * 10000;

	DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Red);

	LookDirection = FVector::ZeroVector;
	MouseShift = FVector::ZeroVector;
}
