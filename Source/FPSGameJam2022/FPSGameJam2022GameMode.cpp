// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSGameJam2022GameMode.h"
#include "FPSGameJam2022Character.h"
#include "UObject/ConstructorHelpers.h"

AFPSGameJam2022GameMode::AFPSGameJam2022GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
