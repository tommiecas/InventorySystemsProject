// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UINV_CompositeBase.h"
#include "INV_Composite.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_Composite : public UINV_CompositeBase
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void ApplyFunction(FuncType Function) override;
	virtual void Collapse() override;
	
private:
	UPROPERTY()
	TArray<TObjectPtr<UINV_CompositeBase>> Children;
	
public:
	
};
