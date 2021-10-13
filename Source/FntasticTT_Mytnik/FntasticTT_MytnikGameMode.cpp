// Copyright Epic Games, Inc. All Rights Reserved.

#include "FntasticTT_MytnikGameMode.h"
#include "FntasticTT_MytnikCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFntasticTT_MytnikGameMode::AFntasticTT_MytnikGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
