// Copyright Epic Games, Inc. All Rights Reserved.

#include "sixGameMode.h"
#include "sixCharacter.h"
#include "UObject/ConstructorHelpers.h"

AsixGameMode::AsixGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
