// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Inventory/InventoryBase/INV_InventoryBase.h"
#include "Widgets/ItemDescription/INV_ItemDescriptionWidget.h"
#include "INV_SpatialInventory.generated.h"

class UINV_ItemDescriptionWidget;
class UCanvasPanel;
class UButton;
class UINV_InventoryGrid;
class UWidgetSwitcher;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_SpatialInventory : public UINV_InventoryBase
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FINV_SlotAvailabilityResult HasRoomForItem(UINV_ItemComponent* ItemComponent) const override;
	virtual void OnItemHovered(UINV_InventoryItem* Item) override;
	virtual void OnItemUnhovered() override;
	virtual bool HasHoverItem() const override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> Switcher;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UINV_InventoryGrid> Grid_Equippables;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UINV_InventoryGrid> Grid_Consumables;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UINV_InventoryGrid> Grid_Craftables;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Equippables;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Consumables;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Craftables;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UINV_ItemDescriptionWidget> ItemDescriptionWidgetClass;

	UPROPERTY()
	TObjectPtr<UINV_ItemDescriptionWidget> ItemDescriptionWidget;

	FTimerHandle DescriptionTimer;

	float DescriptionTimerDelay{0.5f};

	

	UFUNCTION()
	void ShowEquippables();

	UFUNCTION()
	void ShowConsumables();

	UFUNCTION()
	void ShowCraftables();
	
	void DisableButton(UButton* Button);
	void SetActiveGrid(UINV_InventoryGrid* Grid, UButton* Button);
	void SetItemDescriptionWidgetSizeAndPosition(UINV_ItemDescriptionWidget* DescriptionWidget, UCanvasPanel* Panel) const;;
	
	TWeakObjectPtr<UINV_InventoryGrid> ActiveGrid;

public:
	UINV_ItemDescriptionWidget* GetItemDescriptionWidget();
	

	

	
};

