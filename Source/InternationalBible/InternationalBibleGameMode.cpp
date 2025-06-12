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

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true; //마우스 관련 처리, 컨트롤러
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;

	GetBible(28, 1, 1);
}

FString AInternationalBibleGameMode::GetBible(int32 Index, int32 BookNumber, int32 Chapter)
{
	UDataTable* SelectedTable = Tables[Index];

	TArray<FName> RowNames = SelectedTable->GetRowNames();

	FString ColectStrings;

	for (auto& Key : RowNames)
	{
		FAfrikaansTable* Info = SelectedTable->FindRow<FAfrikaansTable>(Key, FString(""));
		if (Info->BookNumber == BookNumber && Info->Chapter == Chapter)
		{
			ColectStrings.Append(Info->Text + "\n\n\n\n\n");
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *ColectStrings);

	return ColectStrings;
}

TArray<FString> AInternationalBibleGameMode::GetBibles(int32 Index, int32 BookNumber, int32 Chapter)
{
	UDataTable* SelectedTable = Tables[Index];

	TArray<FName> RowNames = SelectedTable->GetRowNames();

	TArray<FString> ColectStrings;

	for (auto& Key : RowNames)
	{
		FAfrikaansTable* Info = SelectedTable->FindRow<FAfrikaansTable>(Key, FString(""));
		if (Info->BookNumber == BookNumber && Info->Chapter == Chapter)
		{
			ColectStrings.Add(Info->Text);
		}
	}

	return ColectStrings;
}
