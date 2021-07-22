// Fill out your copyright notice in the Description page of Project Settings.


#include "TDBaseCharacterAnimInstance.h"
#include "Characters/TDBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UTDBaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ATDBaseCharacter>(),
		TEXT("UXFBaseCharacterAnimInstance::NativeBeginPlay UXFBaseCharacterAnimInstance can be used only with AXFBaseCharacter"));
	CachedBaseCharacter = StaticCast<ATDBaseCharacter*>(TryGetPawnOwner());
}

void UTDBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!CachedBaseCharacter.IsValid())
	{
		return;
	}

	UCharacterMovementComponent* CharacterMovement = CachedBaseCharacter->GetCharacterMovement();
	Speed = CharacterMovement->Velocity.Size();
	bIsFalling = CharacterMovement->IsFalling();
}
