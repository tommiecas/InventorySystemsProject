// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Utilities/INV_WidgetUtilities.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/Widget.h"

FVector2D UINV_WidgetUtilities::GetWidgetPosition(const UWidget* Widget)
{
	const FGeometry Geometry = Widget->GetCachedGeometry();
	FVector2D PixelPosition;
	FVector2D ViewportPosition;
	USlateBlueprintLibrary::LocalToViewport(Widget, Geometry, USlateBlueprintLibrary::GetLocalTopLeft(Geometry), PixelPosition, ViewportPosition);;
	return ViewportPosition;
}

FVector2D UINV_WidgetUtilities::GetWidgetSize(UWidget* Widget)
{
	const FGeometry Geometry = Widget->GetCachedGeometry();
	return Geometry.GetLocalSize();
}

bool UINV_WidgetUtilities::IsWithinBounds(const FVector2D& BoundaryPosition, const FVector2D& WidgetSize, const FVector2D& MousePosition)
{
	return MousePosition.X >= BoundaryPosition.X && MousePosition.X <= (BoundaryPosition.X + WidgetSize.X) &&
		MousePosition.Y >= BoundaryPosition.Y && MousePosition.Y <= (BoundaryPosition.Y + WidgetSize.Y);
}

int32 UINV_WidgetUtilities::GetIndexFromPosition(const FIntPoint& Position, const int32 Columns)
{
	return Position.X + Position.Y * Columns;
}

FIntPoint UINV_WidgetUtilities::GetPositionFromIndex(const int32 Index, const int32 Columns)
{
	return FIntPoint(Index % Columns, Index / Columns);
}
