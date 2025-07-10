// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "INV_HoverItem.generated.h"

class UINV_InventoryItem;
/**
 *  The Hover Item is the item that will appear and follow the mouse
 *  when an inventory item on the grid has been clicked.
 */
class UImage;
class UTextBlock;
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_HoverItem : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateStackCount(int32 Count) const;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;
	
	int32 PreviousGridIndex;
	FIntPoint GridDimensions;
	TWeakObjectPtr<UINV_InventoryItem> InventoryItem;
	bool bIsStackable{false};
	int32 StackCount{0};
	
public:
	void SetImageBrush(const FSlateBrush& Brush) const;
	FGameplayTag GetItemType() const;
	bool IsStackable() const { return bIsStackable; }
	void SetIsStackable(const bool bStacks);
	int32 GetPreviousGridIndex() const { return PreviousGridIndex; }
	void SetPreviousGridIndex(int32 Index) { PreviousGridIndex = Index; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	UINV_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
	void SetInventoryItem(UINV_InventoryItem* Item);
	void SetIconColor(const FLinearColor Color) const { Image_Icon->SetColorAndOpacity(Color); }
	int32 GetStackCount() const { return StackCount; }
	void SetStackCount(const int32 Count) { StackCount = Count; }
	void SetStackCount(const int32 Count, const bool bIsItemStackable);
};
