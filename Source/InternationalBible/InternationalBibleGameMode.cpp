// Copyright Epic Games, Inc. All Rights Reserved.

#include "InternationalBibleGameMode.h"
#include "InternationalBibleCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
#include "BibleGameInstance.h"

AInternationalBibleGameMode::AInternationalBibleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	
}

void AInternationalBibleGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<FName> RowNames = Tables[4]->GetRowNames();

	FString Test;

	for (auto& Name : RowNames)
	{
		FAfrikaansTable* Info = Tables[4]->FindRow<FAfrikaansTable>(Name, FString(""));
		if (Info->BookNumber == 1 && Info->Chapter == 1)
		{
			Test.Append(Info->Text + "\n");
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Test);
}
