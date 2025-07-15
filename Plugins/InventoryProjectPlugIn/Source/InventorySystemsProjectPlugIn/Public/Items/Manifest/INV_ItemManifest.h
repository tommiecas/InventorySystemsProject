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


class UINV_CompositeBase;
struct FINV_ItemFragment;
class UINV_InventoryItem;

USTRUCT(BlueprintType)
struct INVENTORYSYSTEMSPROJECTPLUGIN_API FINV_ItemManifest
{
	GENERATED_BODY()

	TArray<TInstancedStruct<FINV_ItemFragment>>& GetFragmentsMutable() { return Fragments; }

	UINV_InventoryItem* Manifest(UObject* NewOuter);
	void AssimilateInventoryFragments(UINV_CompositeBase* CompositeBase) const;
	
	template<typename T> requires std::derived_from<T, FINV_ItemFragment>
	const T* GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag) const;

	template<typename T> requires std::derived_from<T, FINV_ItemFragment>
	const T* GetFragmentOfType() const;

	template<typename T> requires std::derived_from<T, FINV_ItemFragment>
	T* GetFragmentOfTypeMutable();

	template<typename T> requires std::derived_from<T, FINV_ItemFragment>
	TArray<const T*> GetAllFragmentsOfType() const;

	void SpawnPickupActor(const UObject* WorldContextObject, const FVector& SpawnLocation, const FRotator& SpawnRotation);;
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (ExcludeBaseStruct))
	TArray<TInstancedStruct<FINV_ItemFragment>> Fragments;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	EINV_ItemCategory ItemCategory{EINV_ItemCategory::None};

	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (Categories = "GameItems"))
	FGameplayTag ItemType;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<AActor> PickupActorClass;

	void ClearFragments();

	

	

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

template <typename T> requires std::derived_from<T, FINV_ItemFragment>
T* FINV_ItemManifest::GetFragmentOfTypeMutable()
{
	for (TInstancedStruct<FINV_ItemFragment>& Fragment : Fragments)
	{
		if (T* FragmentPtr = Fragment.GetMutablePtr<T>())
		{
			return FragmentPtr;
		}
	}
	
	return nullptr;
}

template <typename T> requires std::derived_from<T, FINV_ItemFragment>
TArray<const T*> FINV_ItemManifest::GetAllFragmentsOfType() const
{
	TArray<const T*> Result;
	for (const TInstancedStruct<FINV_ItemFragment>& Fragment : Fragments)
	{
		if (const T* FragmentPtr = Fragment.GetPtr<T>())
		{
			Result.Add(FragmentPtr);
		}
	}
	return Result;
}
