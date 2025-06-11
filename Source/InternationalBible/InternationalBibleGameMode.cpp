// Copyright Epic Games, Inc. All Rights Reserved.

#include "InternationalBibleGameMode.h"
#include "InternationalBibleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInternationalBibleGameMode::AInternationalBibleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
