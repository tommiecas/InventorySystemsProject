// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Composite/INV_Leaf_LabeledValue.h"

#include "Components/TextBlock.h"

void UINV_Leaf_LabeledValue::NativePreConstruct()
{
	Super::NativePreConstruct();

	FSlateFontInfo LabelFontInfo = Text_Label->GetFont();
	LabelFontInfo.Size = FontSize_Label;
	Text_Label->SetFont(LabelFontInfo);

	FSlateFontInfo ValueFontInfo = Text_Value->GetFont();
	ValueFontInfo.Size = FontSize_Value;
	Text_Value->SetFont(ValueFontInfo);
}

void UINV_Leaf_LabeledValue::SetText_Label(const FText& Text, bool bCollapse) const
{
	if (bCollapse)
	{
		Text_Value->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	Text_Label->SetText(Text);
}

void UINV_Leaf_LabeledValue::SetText_Value(const FText& Text, bool bCollapse) const
{
	if (bCollapse)
	{
		Text_Value->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	Text_Value->SetText(Text);
}
