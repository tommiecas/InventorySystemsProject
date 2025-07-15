// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Composite/INV_Leaf_Text.h"

#include "Components/TextBlock.h"

void UINV_Leaf_Text::NativePreConstruct()
{
	Super::NativePreConstruct();

	FSlateFontInfo FontInfo = Text_LeafText->GetFont();
	FontInfo.Size = FontSize;
	
	Text_LeafText->SetFont(FontInfo);
}

void UINV_Leaf_Text::SetText(const FText& Text) const
{
	Text_LeafText->SetText(Text);
}

FText UINV_Leaf_Text::GetText() const
{
	return Text_LeafText->GetText();
}

FVector2D UINV_Leaf_Text::GetTextSize() const
{
	return Text_LeafText->GetDesiredSize();
}

void UINV_Leaf_Text::SetTextColor(const FLinearColor& Color) const
{
	Text_LeafText->SetColorAndOpacity(Color);
	Text_LeafText->SetShadowColorAndOpacity(Color);
}

void UINV_Leaf_Text::SetTextShadowOffset(const FVector2D& Offset) const
{
	Text_LeafText->SetShadowOffset(Offset);
}








