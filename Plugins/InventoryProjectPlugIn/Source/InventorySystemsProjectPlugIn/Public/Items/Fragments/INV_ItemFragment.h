#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "INV_ItemFragment.generated.h"

/**************************
*****                 *****
*****   BASE STRUCT   *****
*****                 *****
**************************/

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

private:
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (Categories="FragmentTags"))
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;

public:
	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(FGameplayTag Tag) { FragmentTag = Tag; }
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
struct FINV_ImageFragment : public FINV_ItemFragment
{
	GENERATED_BODY()

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
struct FINV_ConsumableFragment : public FINV_ItemFragment
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) {}
private:

public:
	
};

/************************************
*****                           *****
*****   HEASLTH POTION STRUCT   *****
*****                           *****
************************************/

USTRUCT(BlueprintType)
struct FINV_HealthPotionFragment : public FINV_ConsumableFragment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float HealAmount = 20.f;

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
struct FINV_ManaPotionFragment : public FINV_ConsumableFragment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float ManaAmount = 20.f;

	virtual void OnConsume(APlayerController* PlayerController) override;
private:

public:
	
};
