// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ItemDescription/INV_ItemDescriptionWidget.h"

#include "Components/SizeBox.h"

FVector2D UINV_ItemDescriptionWidget::GetSizeBoxSize() const
{
	return SizeBox->GetDesiredSize();
}
