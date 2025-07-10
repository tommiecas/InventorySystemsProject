// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Utilities/INV_WidgetUtilities.h"

int32 UINV_WidgetUtilities::GetIndexFromPosition(const FIntPoint& Position, const int32 Columns)
{
	return Position.X + Position.Y * Columns;
}

FIntPoint UINV_WidgetUtilities::GetPositionFromIndex(const int32 Index, const int32 Columns)
{
	return FIntPoint(Index % Columns, Index / Columns);
}
