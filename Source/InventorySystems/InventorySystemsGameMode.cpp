// Copyright Epic Games, Inc. All Rights Reserved.

#include "InventorySystemsGameMode.h"
#include "InventorySystemsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventorySystemsGameMode::AInventorySystemsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
