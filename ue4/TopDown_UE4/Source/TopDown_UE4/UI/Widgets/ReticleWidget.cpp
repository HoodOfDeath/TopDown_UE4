// Fill out your copyright notice in the Description page of Project Settings.


#include "ReticleWidget.h"

#include "Components/CanvasPanelSlot.h"

void UReticleWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(this->Slot);
	FVector2D MousePos;
	if (GetOwningPlayer()->GetMousePosition(MousePos.X, MousePos.Y))
	{
		CanvasSlot->SetPosition(MousePos);
	}
	int32 ViewportX, ViewportY;
	
	GetOwningPlayer()->GetViewportSize(ViewportX, ViewportY);
	//UE_LOG(LogTemp, Log, TEXT("Mouse viewport pos %s"), *MousePos.ToString())
	//UE_LOG(LogTemp, Log, TEXT("Viewport size %d * %d"), ViewportX, ViewportY)
}
