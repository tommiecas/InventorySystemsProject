// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "UINV_CompositeBase.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_CompositeBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void Collapse();
	void Expand();

	using FuncType = TFunction<void(UINV_CompositeBase*)>;
	virtual void  ApplyFunction(FuncType Function) {}

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag FragmentTag;

public:
	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(const FGameplayTag& Tag) { FragmentTag = Tag; }
};
