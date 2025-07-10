// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Components/INV_ItemComponent.h"
#include "Net/UnrealNetwork.h"


UINV_ItemComponent::UINV_ItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PickupMessage = FString("E - Pick Up Item");

}

void UINV_ItemComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ItemManifest);
}






