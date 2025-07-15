#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StructUtils/InstancedStruct.h"
#include "INV_ItemFragment.generated.h"

/**************************
*****                 *****
*****   BASE STRUCT   *****
*****                 *****
**************************/

struct FINV_ConsumeModifier;
class UINV_CompositeBase;

USTRUCT(BlueprintType)
struct FINV_ItemFragment
{
	GENERATED_BODY()

	FINV_ItemFragment() {}
	FINV_ItemFragment(const FINV_ItemFragment&) = default;
	FINV_ItemFragment& operator=(const FINV_ItemFragment&) = default;
	FINV_ItemFragment(FINV_ItemFragment&&) = default;
	FINV_ItemFragment& operator=(FINV_ItemFragment&&) = default;
	virtual ~FINV_ItemFragment() {}

	virtual void Manifest();

private:
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (Categories="FragmentTags"))
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;

public:
	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(FGameplayTag Tag) { FragmentTag = Tag; }
};

/*********************************************
*****                                    *****
*****   INVENTORY ITEM FRAGMENT STRUCT   *****
*****                                    *****
*********************************************/

/*
 * Item Fragment specifically for assimilation into a widget
 */

USTRUCT(BlueprintType)
struct FINV_InventoryItemFragment : public FINV_ItemFragment
{
	GENERATED_BODY()

	virtual void Assimilate(UINV_CompositeBase* CompositeBase) const;

protected:
	bool MatchesWidgetTag(const UINV_CompositeBase* CompositeBase) const;

private:

public:

};

/**************************
*****                 *****
*****   GRID STRUCT   *****
*****                 *****
**************************/

USTRUCT(BlueprintType)
struct FINV_GridFragment : public FINV_ItemFragment
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FIntPoint GridSize{1, 1};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float GridPadding{0.f};

public:
	FIntPoint GetGridSize() const { return GridSize; }
	float GetGridPadding() const { return GridPadding; }
	void SetGridSize(FIntPoint Size) { GridSize = Size; }
	void SetGridPadding(float Padding) { GridPadding = Padding; }
	FIntPoint GetGridSizeAndPadding() const { return FIntPoint(GridSize.X + GridPadding, GridSize.Y + GridPadding); }
	
};

/***************************
*****                  *****
*****   IMAGE STRUCT   *****
*****                  *****
***************************/

USTRUCT(BlueprintType)
struct FINV_ImageFragment : public FINV_InventoryItemFragment
{
	GENERATED_BODY()

public:
	virtual void Assimilate(UINV_CompositeBase* CompositeBase) const override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UTexture2D> Icon{nullptr};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FVector2D IconDimensions{44.f, 44.f};

public:
	FVector2D GetIconDimensions() const { return IconDimensions; }
	void SetIconDimensions(FVector2D Dimensions) { IconDimensions = Dimensions; }
	void SetIcon(UTexture2D* NewIcon) { Icon = NewIcon; }
	UTexture2D* GetIcon() const { return Icon; }
};

/***************************
*****                  *****
*****   TEXT STRUCT    *****
*****                  *****
***************************/

USTRUCT(BlueprintType)
struct FINV_TextFragment : public FINV_InventoryItemFragment
{
	GENERATED_BODY()

public:
	virtual void Assimilate(UINV_CompositeBase* CompositeBase) const override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FText FragmentText;

public:
	FText GetFragmentText() const { return FragmentText; }
	void SetFragmentText(FText Text) { FragmentText = Text; }
};

/************************************
*****                           *****
*****   LABELED NUMBER STRUCT   *****
*****                           *****
************************************/

USTRUCT(BlueprintType)
struct FINV_LabeledNumberFragment : public FINV_InventoryItemFragment
{
	GENERATED_BODY()

	virtual void Manifest() override;

	//When Manifesting for the first time, this fragment will randomize.
	// However, once equipped and dropped, an item should retain the same value,
	// so randomization should not occur
	
	bool bRandomizedOnManifest{true};
	
public:
	virtual void Assimilate(UINV_CompositeBase* CompositeBase) const override;
	
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FText Text_Label{};

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	float Value{0.f};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float Min{0.f};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float Max{0.f};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	bool bCollapseLabel{false};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	bool bCollapseValue{false};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 MinFractionalDigits{1};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 MaxFractionalDigits{1};

public:
	float GetValue() const { return Value; }
	void SetValue(float NewValue) { Value = NewValue; }
	float GetMin() const { return Min; }
	void SetMin(float NewMin) { Min = NewMin; }
	float GetMax() const { return Max; }
	void SetMax(float NewMax) { Max = NewMax; }
	bool GetCollapseLabel() const { return bCollapseLabel; }
	void SetCollapseLabel(bool NewCollapseLabel) { bCollapseLabel = NewCollapseLabel; }
	bool GetCollapseValue() const { return bCollapseValue; }
	
};


/*******************************
*****                      *****
*****   STACKABLE STRUCT   *****
*****                      *****
*******************************/

USTRUCT(BlueprintType)
struct FINV_StackableFragment : public FINV_ItemFragment
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 MaxStackSize{1};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 StackCount{1};

public:
	int32 GetMaxStackSize() const { return MaxStackSize; }
	int32 GetStackCount() const { return StackCount; }
	void SetMaxStackSize(const int32 NewMaxStackSize) { MaxStackSize = NewMaxStackSize; }
	void SetStackCount(const int32 NewStackCount) { StackCount = NewStackCount; }
	void AddStackCount(const int32 NewStackCount) { StackCount += NewStackCount; }
	void RemoveStackCount(const int32 NewStackCount) { StackCount -= NewStackCount; }
	bool CanStackWith(const FINV_StackableFragment& Other) const { return MaxStackSize == Other.MaxStackSize; }
};

/********************************
*****                       *****
*****   CONSUMABLE STRUCT   *****
*****                       *****
********************************/

USTRUCT(BlueprintType)
struct FINV_ConsumableFragment : public FINV_InventoryItemFragment
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController);
	virtual void Assimilate(UINV_CompositeBase* CompositeBase) const override;
	virtual void Manifest() override;
private:
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (ExcludeBaseStruct))
	TArray<TInstancedStruct<FINV_ConsumeModifier>> ConsumeModifiers;
public:
	
};

/**************************************
*****                             *****
*****   CONSUME MODIFIER STRUCT   *****
*****                             *****
**************************************/

USTRUCT(BlueprintType)
struct FINV_ConsumeModifier : public FINV_LabeledNumberFragment
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) {}
	
public:
	
	
private:
	
	
	

public:
	
};

/************************************
*****                           *****
*****   HEASLTH POTION STRUCT   *****
*****                           *****
************************************/

USTRUCT(BlueprintType)
struct FINV_HealthPotionFragment : public FINV_ConsumeModifier
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) override;
private:

public:
	
};

/*********************************
*****                        *****
*****   MANA POTION STRUCT   *****
*****                        *****
*********************************/

USTRUCT(BlueprintType)
struct FINV_ManaPotionFragment : public FINV_ConsumeModifier
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) override;
private:

public:
	
};
