// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/GridSlots/INV_GridSlot.h"

#include "Components/Image.h"
#include "Items/INV_InventoryItem.h"

void UINV_GridSlot::SetInventoryItem(UINV_InventoryItem* Item)
{
	InventoryItem = Item;
}

void UINV_GridSlot::SetImageBrush(const FSlateBrush& Brush) const
{
	Image_GridSlot->SetBrush(Brush);
	Image_GridSlot->SetVisibility(ESlateVisibility::Visible);
	Image_GridSlot->SetOpacity(1.0f);
}

void UINV_GridSlot::SetOccupiedTexture()
{
	GridSlotState = EINV_GridSlotState::Occupied;
	Image_GridSlot->SetBrush(Brush_Occupied);
}

void UINV_GridSlot::SetUnoccupiedTexture()
{
	GridSlotState = EINV_GridSlotState::Unoccupied;
	Image_GridSlot->SetBrush(Brush_Unoccupied);
}

void UINV_GridSlot::SetSelectedTexture()
{
	GridSlotState = EINV_GridSlotState::Selected;
	Image_GridSlot->SetBrush(Brush_Selected);
}

void UINV_GridSlot::SetGrayedOutTexture()
{
	GridSlotState = EINV_GridSlotState::GrayedOut;
	Image_GridSlot->SetBrush(Brush_GrayedOut);
}

/* void UINV_GridSlot::SetInventoryItem(UINV_InventoryItem* Item)
{
	if (Item && Item->IsValidLowLevelFast())
	{
		InventoryItem = MakeWeakObjectPtr(Item);  // ✅ safest
	}
	else
	{
		InventoryItem = nullptr;
	}
}*/