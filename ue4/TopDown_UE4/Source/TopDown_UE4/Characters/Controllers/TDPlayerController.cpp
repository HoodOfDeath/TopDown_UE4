// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"
#include "Characters/TDBaseCharacter.h"
#include "UI/Widgets/PlayerHUDWidget.h"

void ATDPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<ATDBaseCharacter>(InPawn);
	CreateAndInitializeWidgets();
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
	InputComponent->BindAxis("MoveForwardStick", this, &ATDPlayerController::MoveForwardStick);
	InputComponent->BindAxis("MoveRightStick", this, &ATDPlayerController::MoveRightStick);
	
	InputComponent->BindAxis("LookUp", this, &ATDPlayerController::LookUp);
	InputComponent->BindAxis("LookRight", this, &ATDPlayerController::LookRight);
	InputComponent->BindAxis("MouseUp", this, &ATDPlayerController::MouseUp);
	InputComponent->BindAxis("MouseRight", this, &ATDPlayerController::MouseRight);

	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATDPlayerController::HoldFire);
	InputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ATDPlayerController::ReleaseFire);

	InputComponent->BindAction("Dash", EInputEvent::IE_Pressed, this, &ATDPlayerController::HoldDash);
	InputComponent->BindAction("Dash", EInputEvent::IE_Released, this, &ATDPlayerController::ReleaseDash);
	
	InputComponent->BindAction("ChargedShot", EInputEvent::IE_Pressed, this, &ATDPlayerController::HoldChargedShot);
	InputComponent->BindAction("ChargedShot", EInputEvent::IE_Released, this, &ATDPlayerController::ReleaseChargedShot);

	InputComponent->BindAction("Parry", EInputEvent::IE_Pressed, this, &ATDPlayerController::Parry);
	
	InputComponent->BindAction("Slash", EInputEvent::IE_Pressed, this, &ATDPlayerController::HoldSlash);
	InputComponent->BindAction("Slash", EInputEvent::IE_Released, this, &ATDPlayerController::ReleaseSlash);
	
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATDPlayerController::Jump);
}

void ATDPlayerController::CreateAndInitializeWidgets()
{
	if (!IsValid(PlayerHUDWidget))
	{
		PlayerHUDWidget = CreateWidget<UPlayerHUDWidget>(GetWorld(), PlayerHUDWidgetClass);

		if (IsValid(PlayerHUDWidget))
		{
			PlayerHUDWidget->AddToViewport();
		}
	}
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

void ATDPlayerController::MoveForwardStick(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForwardStick(Value);
	}
}

void ATDPlayerController::MoveRightStick(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRightStick(Value);
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

void ATDPlayerController::HoldFire()
{
	UE_LOG(LogTemp, Log, TEXT("Fire"))
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->StartFiring();
	}
}

void ATDPlayerController::ReleaseFire()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->StopFiring();
	}
}

void ATDPlayerController::HoldDash()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->HoldDash();
	}
}

void ATDPlayerController::ReleaseDash()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->ReleaseDash();
	}
}

void ATDPlayerController::HoldChargedShot()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->HoldChargedShot();
	}
}

void ATDPlayerController::ReleaseChargedShot()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->ReleaseChargedShot();
	}
}

void ATDPlayerController::Parry()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Parry();
	}
}

void ATDPlayerController::HoldSlash()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->HoldSlash();
	}
}

void ATDPlayerController::ReleaseSlash()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->ReleaseSlash();
	}
}

void ATDPlayerController::Jump()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}
