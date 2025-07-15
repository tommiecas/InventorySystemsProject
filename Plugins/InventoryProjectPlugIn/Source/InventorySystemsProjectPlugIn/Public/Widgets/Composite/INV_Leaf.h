// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UINV_CompositeBase.h"
#include "INV_Leaf.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_Leaf : public UINV_CompositeBase
{
	GENERATED_BODY()

public:
	virtual void ApplyFunction(FuncType Function) override;
};
