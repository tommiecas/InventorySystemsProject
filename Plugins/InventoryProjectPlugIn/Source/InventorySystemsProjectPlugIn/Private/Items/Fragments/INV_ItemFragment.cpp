#include "Items/Fragments/INV_ItemFragment.h"

void FINV_HealthPotionFragment::OnConsume(APlayerController* PlayerController)
{
	// Get a stats component from the PC or PC->GetPawn()
	// or get the AbilitySystemComponent and apply a Gameplay Effect
	// or call an interface function for Healing()

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Potioon Consumed! Healing by: %f!"), HealAmount));
}

void FINV_ManaPotionFragment::OnConsume(APlayerController* PlayerController)
{
	// Get a stats component from the PC or PC->GetPawn()
	// or get the AbilitySystemComponent and apply a Gameplay Effect
	// or call an interface function for Healing()

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Mana Potioon Consumed! Restoring Mana by: %f!"), ManaAmount));
}
