// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ItemPopUps/INV_ItemPopUpWidget.h"

#include "Components/Button.h"
#include "Components/SizeBox.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"

void UINV_ItemPopUpWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Button_Split->OnClicked.AddDynamic(this, &ThisClass::SplitButtonClicked);
	Button_Drop->OnClicked.AddDynamic(this, &ThisClass::DropButtonClicked);
	Button_Consume->OnClicked.AddDynamic(this, &ThisClass::ConsumeButtonClicked);
	Slider_Split->OnValueChanged.AddDynamic(this, &ThisClass::SliderValueChanged);
}

void UINV_ItemPopUpWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	RemoveFromParent();
}

void UINV_ItemPopUpWidget::SplitButtonClicked()
{
	if (OnSplit.ExecuteIfBound(GetSplitAmount(), GridIndex))
	{
		RemoveFromParent();
	}
}

void UINV_ItemPopUpWidget::DropButtonClicked()
{
	if (OnDrop.ExecuteIfBound(GridIndex))
	{
		RemoveFromParent();
	}
}

void UINV_ItemPopUpWidget::ConsumeButtonClicked()
{
	if (OnConsume.ExecuteIfBound(GridIndex))
	{
		RemoveFromParent();
	}
}

void UINV_ItemPopUpWidget::SliderValueChanged(float Value)
{
	Text_SplitAmount->SetText(FText::AsNumber(FMath::Floor(Value)));
}

void UINV_ItemPopUpWidget::CollapseSplitButton() const
{
	Button_Split->SetVisibility(ESlateVisibility::Collapsed);
	Slider_Split->SetVisibility(ESlateVisibility::Collapsed);
	Text_SplitAmount->SetVisibility(ESlateVisibility::Collapsed);
}

void UINV_ItemPopUpWidget::CollapseConsumeButton() const
{
	Button_Consume->SetVisibility(ESlateVisibility::Collapsed);
}

void UINV_ItemPopUpWidget::SetSliderParams(const float Max, const float Value) const
{
	Slider_Split->SetMaxValue(Max);
	Slider_Split->SetMinValue(1);
	Slider_Split->SetValue(Value);
	Text_SplitAmount->SetText(FText::AsNumber(FMath::Floor(Value)));
}

int32 UINV_ItemPopUpWidget::GetSplitAmount() const
{
	return FMath::Floor(Slider_Split->GetValue());
}

FVector2D UINV_ItemPopUpWidget::GetSizeBoxSize() const
{
	return FVector2D(SizeBox_Root->GetWidthOverride(), SizeBox_Root->GetHeightOverride());
}

void UINV_ItemPopUpWidget::SetSplitAmount(const int32 Amount)
{
	Slider_Split->SetValue(Amount);
	Text_SplitAmount->SetText(FText::AsNumber(Amount));
}

void UINV_ItemPopUpWidget::SetSizeBoxSize(const FVector2D& Size)
{
	SizeBox_Root->SetWidthOverride(Size.X);
	SizeBox_Root->SetHeightOverride(Size.Y);
}
