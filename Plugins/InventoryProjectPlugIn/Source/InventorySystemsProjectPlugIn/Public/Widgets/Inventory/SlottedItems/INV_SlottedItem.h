// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "INV_SlottedItem.generated.h"

class UINV_InventoryItem;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_SlottedItem : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateStackCount(int32 StackCount);

protected:

private:
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;

	int32 GridIndex;

	FIntPoint GridDimensions;

	TWeakObjectPtr<UINV_InventoryItem> InventoryItem;
	bool bIsStackable{false};

	

public:
	bool IsStackable() const { return bIsStackable; }
	void SetIsStackable(const bool bStackable) { bIsStackable = bStackable; }
	UImage* GetImageIcon() const { return Image_Icon; }
	void SetGridIndex(const int32 Index) { GridIndex = Index; }
	int32 GetGridIndex() const { return GridIndex; }
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	void SetInventoryItem(UINV_InventoryItem* Item);
	UINV_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
	void SetIconColor(const FLinearColor Color) const { Image_Icon->SetColorAndOpacity(Color); }
	void SetImageBrush(const FSlateBrush& Brush) const;
	
};
