// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlatformerCPPGameMode.h"
#include "PlatformerCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlatformerCPPGameMode::APlatformerCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
