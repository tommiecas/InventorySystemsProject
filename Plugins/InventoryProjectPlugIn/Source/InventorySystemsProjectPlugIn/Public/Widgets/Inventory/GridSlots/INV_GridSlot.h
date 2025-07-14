// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "INV_GridSlot.generated.h"

class UINV_ItemPopUpWidget;
class UINV_InventoryItem;
class UImage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridSlotEvent, int32, GridIndex, const FPointerEvent&, MouseEvent);

UENUM(BlueprintType)
enum class EINV_GridSlotState : uint8
{
	Unoccupied,
	Occupied,
	Selected,
	GrayedOut
};
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_GridSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	
	FGridSlotEvent GridSlotClicked;
	FGridSlotEvent GridSlotHovered;
	FGridSlotEvent GridSlotUnhovered;
	
protected:

private:
	int32 StackCount{0};
	bool bAvailable{true};
	int32 TileIndex{INDEX_NONE};
	int32 UpperLeftIndex{INDEX_NONE};
	TWeakObjectPtr<UINV_InventoryItem> InventoryItem;
	TWeakObjectPtr<UINV_ItemPopUpWidget> ItemPopUpWidget;
	
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_GridSlot;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_Unoccupied;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_Occupied;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_Selected;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_GrayedOut;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	EINV_GridSlotState GridSlotState{EINV_GridSlotState::Unoccupied};

	UFUNCTION()
	void OnItemPopUpDestruct(UUserWidget* Menu);



public:
	void SetTileIndex(int32 Index) { TileIndex = Index; }
	int32 GetTileIndex() const { return TileIndex; }
	EINV_GridSlotState GetGridSlotState() const { return GridSlotState; }
	void SetGridSlotState(const EINV_GridSlotState State) { GridSlotState = State; }
	void SetImageBrush(const FSlateBrush& Brush) const;
	void SetOccupiedTexture();
	void SetUnoccupiedTexture();
	void SetSelectedTexture();
	void SetGrayedOutTexture();
	TWeakObjectPtr<UINV_InventoryItem> GetInventoryItem() const { return InventoryItem; }
	void SetInventoryItem(UINV_InventoryItem* Item);
	void SetStackCount(const int32 Count) { StackCount = Count; }
	int32 GetStackCount() const { return StackCount; }
	int32 GetIndex() const { return TileIndex; }
	void SetIndex(const int32 Index) { TileIndex = Index; }
	void SetIndex(const FIntPoint& Point) { TileIndex = Point.X + Point.Y * 10; }
	bool IsAvailable() const { return bAvailable; }
	void SetAvailable(const bool bIsAvailable) { bAvailable = bIsAvailable; }
	FIntPoint GetIndexAsPoint() const { return FIntPoint(TileIndex % 10, TileIndex / 10); }
	FIntPoint GetIndexAsPoint(const int32 GridSize) const { return FIntPoint(TileIndex % GridSize, TileIndex / GridSize); }
	FIntPoint GetIndexAsPoint(const FIntPoint& GridDimensions) const { return FIntPoint(TileIndex % GridDimensions.X, TileIndex / GridDimensions.X); }
	FIntPoint GetIndexAsPoint(const FIntPoint& GridDimensions, const int32 GridSize) const { return FIntPoint(TileIndex % GridDimensions.X, TileIndex / GridDimensions.X); }
	void SetUpperLeftIndex(const int32 Index) { UpperLeftIndex = Index; }
	int32 GetUpperLeftIndex() const { return UpperLeftIndex; }
	void SetUpperLeftIndex(const FIntPoint& Point) { UpperLeftIndex = Point.X + Point.Y * 10; }
	FIntPoint GetUpperLeftIndexAsPoint() const { return FIntPoint(UpperLeftIndex % 10, UpperLeftIndex / 10); }
	FIntPoint GetUpperLeftIndexAsPoint(const int32 GridSize) const { return FIntPoint(UpperLeftIndex % GridSize, UpperLeftIndex / GridSize); }
	FIntPoint GetUpperLeftIndexAsPoint(const FIntPoint& GridDimensions) const { return FIntPoint(UpperLeftIndex % GridDimensions.X, UpperLeftIndex / GridDimensions.X); }
	void SetItemPopUpWidget(UINV_ItemPopUpWidget* PopUpWidget);
	UINV_ItemPopUpWidget* GetItemPopUpWidget() const;
};
