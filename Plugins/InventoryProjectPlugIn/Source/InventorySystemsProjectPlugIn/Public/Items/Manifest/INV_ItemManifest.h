#pragma once

#include "CoreMinimal.h"
#include "Types/INV_GridTypes.h"
#include "StructUtils/InstancedStruct.h"
#include "GameplayTagContainer.h"
#include "INV_ItemManifest.generated.h"

/**
 * The item Manifest constains all of the nbecessary data
 * for creating a new Inventory Item
 */


struct FINV_ItemFragment;
class UINV_InventoryItem;

USTRUCT(BlueprintType)
struct INVENTORYSYSTEMSPROJECTPLUGIN_API FINV_ItemManifest
{
	GENERATED_BODY()

	UINV_InventoryItem* Manifest(UObject* NewOuter);
	
	template<typename T> requires std::derived_from<T, FINV_ItemFragment>
	const T* GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag) const;

	template<typename T> requires std::derived_from<T, FINV_ItemFragment>
	const T* GetFragmentOfType() const;
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (ExcludeBaseStruct))
	TArray<TInstancedStruct<FINV_ItemFragment>> Fragments;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	EINV_ItemCategory ItemCategory{EINV_ItemCategory::None};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag ItemType;

	

	

public:
	EINV_ItemCategory GetItemCategory() const { return ItemCategory; }
	FGameplayTag GetItemType() const { return ItemType; }
};

template<typename T>
requires std::derived_from<T, FINV_ItemFragment>
const T* FINV_ItemManifest::GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag) const
{
	for (const TInstancedStruct<FINV_ItemFragment>& Fragment : Fragments)
	{
		if (const T* FragmentPtr = Fragment.GetPtr<T>())
		{
			if (!FragmentPtr->GetFragmentTag().MatchesTagExact(FragmentTag)) continue;
			return FragmentPtr;
		}
	}
	return nullptr;
}

template <typename T> requires std::derived_from<T, FINV_ItemFragment>
const T* FINV_ItemManifest::GetFragmentOfType() const
{
	for (const TInstancedStruct<FINV_ItemFragment>& Fragment : Fragments)
	{
		if (const T* FragmentPtr = Fragment.GetPtr<T>())
		{
			return FragmentPtr;
		}
	}
	return nullptr;
}
