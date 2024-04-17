// Copyright Epic Games, Inc. All Rights Reserved.

#include "InventoryProjectCppGameMode.h"
#include "InventoryProjectCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventoryProjectCppGameMode::AInventoryProjectCppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
