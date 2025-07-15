// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Composite/INV_Leaf_Image.h"

#include "Components/Image.h"
#include "Components/SizeBox.h"

void UINV_Leaf_Image::SetImage(UTexture2D* Texture) const
{
	Image_Icon->SetBrushFromTexture(Texture);
}

void UINV_Leaf_Image::SetSizeBoxSize(const FVector2D& Size) const
{
	SizeBox_Icon->SetWidthOverride(Size.X);
	SizeBox_Icon->SetHeightOverride(Size.Y);
}

void UINV_Leaf_Image::SetImageSize(const FVector2D& Size) const
{
	Image_Icon->SetDesiredSizeOverride(Size);
}

FVector2D UINV_Leaf_Image::GetImageSize() const
{
	return Image_Icon->GetDesiredSize();
}
