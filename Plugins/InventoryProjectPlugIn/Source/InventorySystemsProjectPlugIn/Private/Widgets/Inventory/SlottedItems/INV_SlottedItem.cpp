// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/SlottedItems/INV_SlottedItem.h"
#include "Items/INV_InventoryItem.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "InventoryManagement/Utilities/INV_InventoryStatics.h"

FReply UINV_SlottedItem::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	OnSlottedItemClicked.Broadcast(GridIndex, MouseEvent);
	return FReply::Handled();
}

void UINV_SlottedItem::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UINV_InventoryStatics::ItemHovered(GetOwningPlayer(), InventoryItem.Get());
}

void UINV_SlottedItem::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	UINV_InventoryStatics::ItemUnhovered(GetOwningPlayer());UINV_InventoryStatics::ItemUnhovered(GetOwningPlayer());
}

void UINV_SlottedItem::UpdateStackCount(int32 StackCount)
{
	if (StackCount > 0)
	{
		Text_StackCount->SetVisibility(ESlateVisibility::Visible);
		Text_StackCount->SetText(FText::AsNumber(StackCount));
	}
	else
	{
		Text_StackCount->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UINV_SlottedItem::SetInventoryItem(UINV_InventoryItem* Item)
{
	InventoryItem = Item;
}

void UINV_SlottedItem::SetImageBrush(const FSlateBrush& Brush) const 
{
	Image_Icon->SetBrush(Brush);
}
