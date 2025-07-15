// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "INV_Leaf.h"
#include "INV_Leaf_Text.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_Leaf_Text : public UINV_Leaf
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_LeafText;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 FontSize{12};

public:
	void SetText(const FText& Text) const;
	FText GetText() const;
	FVector2D GetTextSize() const;
	void SetTextColor(const FLinearColor& Color) const;
	void SetTextShadowOffset(const FVector2D& Offset) const;
	
};
