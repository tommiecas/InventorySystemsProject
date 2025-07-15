// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Composite/INV_Composite.h"
#include "INV_ItemDescriptionWidget.generated.h"

class USizeBox;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_ItemDescriptionWidget : public UINV_Composite
{
	GENERATED_BODY()

public:

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox;
	
public:
	FVector2D GetSizeBoxSize() const;
	
};
