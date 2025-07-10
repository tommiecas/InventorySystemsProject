// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/INV_InventoryItem.h"

#include "Items/Fragments/INV_ItemFragment.h"
#include "Net/UnrealNetwork.h"
#include "Items/Manifest/INV_ItemManifest_InstancedStructSupport.h"


void UINV_InventoryItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ItemManifest);
	DOREPLIFETIME(ThisClass, TotalStackCount);
}

void UINV_InventoryItem::SetItemManifest(const FINV_ItemManifest& Manifest)
{
	ItemManifest = FInstancedStruct::Make<FINV_ItemManifest>(Manifest);
}

bool UINV_InventoryItem::IsStackable() const
{
	const FINV_StackableFragment* Stackable = GetItemManifest().GetFragmentOfType<FINV_StackableFragment>();
	return Stackable != nullptr;
}
