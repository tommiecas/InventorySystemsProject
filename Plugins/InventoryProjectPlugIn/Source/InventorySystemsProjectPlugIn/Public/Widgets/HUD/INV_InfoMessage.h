// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "INV_InfoMessage.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMSPROJECTPLUGIN_API UINV_InfoMessage : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	UFUNCTION(BlueprintImplementableEvent, Category="Inventory")
	void MessageShow();

	UFUNCTION(BlueprintImplementableEvent, Category="Inventory")
	void MessageHide();

	void SetMessage(const FText& Message);
	

protected:

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_Message;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float MessageLifetime{3.f};

	FTimerHandle MessageTimer;
	bool bIsMessageActive{false};
	
};
