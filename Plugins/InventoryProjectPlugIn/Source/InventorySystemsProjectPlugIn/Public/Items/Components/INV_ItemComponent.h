// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/Manifest/INV_ItemManifest.h"
#include "INV_ItemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_ItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UINV_ItemComponent();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void InitItemManifest(FINV_ItemManifest CopyOfManifest);
	void OnPickedUpItem();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void PickedUpEffects();

private:

	UPROPERTY(EditAnywhere, Category = "Inventory", Replicated)
	FINV_ItemManifest ItemManifest;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FString PickupMessage;

public:
	FString GetPickupMessage() const { return PickupMessage; }
	FINV_ItemManifest GetItemManifest() const { return ItemManifest; }
};
