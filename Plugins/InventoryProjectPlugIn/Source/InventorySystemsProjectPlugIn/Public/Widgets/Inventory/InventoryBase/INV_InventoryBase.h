// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/INV_GridTypes.h"
#include "INV_InventoryBase.generated.h"

class UINV_ItemComponent;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_InventoryBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual FINV_SlotAvailabilityResult HasRoomForItem(UINV_ItemComponent* ItemComponent) const { return FINV_SlotAvailabilityResult(); }
	virtual void OnItemHovered(UINV_InventoryItem* Item) { }
	virtual void OnItemUnhovered() { }
	virtual bool HasHoverItem() const { return false; }
};
