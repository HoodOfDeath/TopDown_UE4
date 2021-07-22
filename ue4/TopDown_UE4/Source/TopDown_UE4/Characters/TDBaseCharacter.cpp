#include "TDBaseCharacter.h"

ATDBaseCharacter::ATDBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATDBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

