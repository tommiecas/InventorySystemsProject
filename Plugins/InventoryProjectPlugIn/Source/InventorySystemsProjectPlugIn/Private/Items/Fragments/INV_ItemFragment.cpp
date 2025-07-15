#include "Items/Fragments/INV_ItemFragment.h"

#include "Widgets/Composite/INV_Leaf_Image.h"
#include "Widgets/Composite/INV_Leaf_LabeledValue.h"
#include "Widgets/Composite/INV_Leaf_Text.h"
#include "Widgets/Composite/UINV_CompositeBase.h"

void FINV_ItemFragment::Manifest()
{}

void FINV_InventoryItemFragment::Assimilate(UINV_CompositeBase* CompositeBase) const
{
	if (!MatchesWidgetTag(CompositeBase)) return;
	CompositeBase->Expand();
}

bool FINV_InventoryItemFragment::MatchesWidgetTag(const UINV_CompositeBase* CompositeBase) const
{
	return CompositeBase->GetFragmentTag().MatchesTagExact(GetFragmentTag());
}

void FINV_ImageFragment::Assimilate(UINV_CompositeBase* CompositeBase) const
{
	FINV_InventoryItemFragment::Assimilate(CompositeBase);
	if (!MatchesWidgetTag(CompositeBase)) return;

	UINV_Leaf_Image* Image = Cast<UINV_Leaf_Image>(CompositeBase);
	if (!IsValid(Image)) return;

	Image->SetImage(Icon);
	Image->SetSizeBoxSize(IconDimensions);
	Image->SetImageSize(IconDimensions);
}

void FINV_TextFragment::Assimilate(UINV_CompositeBase* CompositeBase) const
{
	FINV_InventoryItemFragment::Assimilate(CompositeBase);
	if (!MatchesWidgetTag(CompositeBase)) return;

	UINV_Leaf_Text* LeafText = Cast<UINV_Leaf_Text>(CompositeBase);
	if (!IsValid(LeafText)) return;

	LeafText->SetText(FragmentText);
}

void FINV_LabeledNumberFragment::Manifest()
{
	FINV_InventoryItemFragment::Manifest();

	if (bRandomizedOnManifest)
	{
		Value = FMath::RandRange(Min, Max);
	}
	bRandomizedOnManifest = false;
}

void FINV_LabeledNumberFragment::Assimilate(UINV_CompositeBase* CompositeBase) const
{
	FINV_InventoryItemFragment::Assimilate(CompositeBase);
	if (!MatchesWidgetTag(CompositeBase)) return;

	UINV_Leaf_LabeledValue* LabeledValue = Cast<UINV_Leaf_LabeledValue>(CompositeBase);
	if (!IsValid(LabeledValue)) return;

	LabeledValue->SetText_Label(Text_Label, bCollapseLabel);

	FNumberFormattingOptions Options;
	Options.MinimumFractionalDigits = MinFractionalDigits;
	Options.MaximumFractionalDigits = MaxFractionalDigits;
	
	LabeledValue->SetText_Value(FText::AsNumber(Value, &Options), bCollapseValue);
	
}

void FINV_ConsumableFragment::OnConsume(APlayerController* PlayerController)
{
	for (auto& Modifier : ConsumeModifiers)
	{
		auto& ModifierRef = Modifier.GetMutable();
		ModifierRef.OnConsume(PlayerController);
	}
}

void FINV_ConsumableFragment::Assimilate(UINV_CompositeBase* CompositeBase) const
{
	FINV_InventoryItemFragment::Assimilate(CompositeBase);
	for (const auto& Modifier : ConsumeModifiers)
	{
		const auto& ModifierRef = Modifier.Get();
		ModifierRef.Assimilate(CompositeBase);
	}
}

void FINV_ConsumableFragment::Manifest()
{
	FINV_InventoryItemFragment::Manifest();
	for (auto& Modifier : ConsumeModifiers)
	{
		auto& ModifierRef = Modifier.GetMutable();
		ModifierRef.Manifest();
	}
}

void FINV_HealthPotionFragment::OnConsume(APlayerController* PlayerController)
{
	// Get a stats component from the PC or PC->GetPawn()
	// or get the AbilitySystemComponent and apply a Gameplay Effect
	// or call an interface function for Healing()

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Potioon Consumed! Healing by: %f!"), GetValue()));
}

void FINV_ManaPotionFragment::OnConsume(APlayerController* PlayerController)
{
	// Get a stats component from the PC or PC->GetPawn()
	// or get the AbilitySystemComponent and apply a Gameplay Effect
	// or call an interface function for Healing()

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Mana Potioon Consumed! Restoring Mana by: %f!"), GetValue()));
}
