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

	GetBible(4);
}

FString AInternationalBibleGameMode::GetBible(int32 Index)
{
	UDataTable* SelectedTable = Tables[Index];

	TArray<FName> RowNames = SelectedTable->GetRowNames();

	FString ColectStrings;

	for (auto& Key : RowNames)
	{
		FAfrikaansTable* Info = SelectedTable->FindRow<FAfrikaansTable>(Key, FString(""));
		if (Info->BookNumber == 1 && Info->Chapter == 1)
		{
			ColectStrings.Append(Info->Text + "\n");
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *ColectStrings);

	return ColectStrings;
}
