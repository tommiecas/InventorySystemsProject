// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryManagement/FastArray/INV_FastArray.h"
#include "INV_InventoryComponent.generated.h"

class UINV_ItemComponent;
class UINV_InventoryItem;
class UINV_InventoryBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, UINV_InventoryItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNoRoomInInventory);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UINV_InventoryComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Inventory")
	void TryAddItem(UINV_ItemComponent* ItemComponent);

	UFUNCTION(Server, Reliable)
	void Server_AddNewItem(UINV_ItemComponent* ItemComponent, int32 StackCount);

	UFUNCTION(Server, Reliable)
	void Server_AddStacksToItem(UINV_ItemComponent* ItemComponent, int32 StackCount, int32 Remainder);

	void ToggleInventoryMenu();
	void AddReplicatedSubObj(UObject* SubObject);

	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;
	FNoRoomInInventory OnNoRoomInInventory;
	
protected:
	virtual void BeginPlay() override;

private:
	TWeakObjectPtr<APlayerController> OwningController;
	
	void ConstructInventory();

	UPROPERTY(Replicated)
	FINV_InventoryFastArray InventoryList;

	UPROPERTY()
	TObjectPtr<UINV_InventoryBase> InventoryMenu;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UINV_InventoryBase> InventoryMenuClass;

	bool bInventoryMenuOpen;
	void OpenInventoryMenu();
	void CloseInventoryMenu();

public:

};
