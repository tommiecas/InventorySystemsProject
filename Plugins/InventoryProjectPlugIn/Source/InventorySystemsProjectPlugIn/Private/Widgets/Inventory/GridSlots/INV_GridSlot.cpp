// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/GridSlots/INV_GridSlot.h"

#include "Components/Image.h"
#include "Items/INV_InventoryItem.h"
#include "Widgets/ItemPopUps/INV_ItemPopUpWidget.h"

void UINV_GridSlot::SetInventoryItem(UINV_InventoryItem* Item)
{
	InventoryItem = Item;
}

void UINV_GridSlot::SetItemPopUpWidget(UINV_ItemPopUpWidget* PopUpWidget)
{
	ItemPopUpWidget = PopUpWidget;
	ItemPopUpWidget->SetGridIndex(GetIndex());
	ItemPopUpWidget->OnNativeDestruct.AddUObject(this, &ThisClass::OnItemPopUpDestruct);
}

UINV_ItemPopUpWidget* UINV_GridSlot::GetItemPopUpWidget() const
{
	return ItemPopUpWidget.Get();
}

void UINV_GridSlot::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	Super::NativeOnMouseEnter(MyGeometry, MouseEvent);
	GridSlotHovered.Broadcast(TileIndex, MouseEvent);
}

void UINV_GridSlot::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	Super::NativeOnMouseLeave(MouseEvent);
	GridSlotUnhovered.Broadcast(TileIndex, MouseEvent);
}

FReply UINV_GridSlot::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	GridSlotClicked.Broadcast(TileIndex, MouseEvent);
	return FReply::Handled();
}

void UINV_GridSlot::OnItemPopUpDestruct(UUserWidget* Menu)
{
	ItemPopUpWidget.Reset();
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