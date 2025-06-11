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

	UBibleGameInstance* GameInstance = Cast<UBibleGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// UDataTable* SkeletalMeshAsset3 = LoadObject<UDataTable>(NULL, Tables[0], NULL, LOAD_None, NULL);

	TArray<FName> RowNames;
	RowNames = Tables[2]->GetRowNames();
	// TArray<FString> EachBibles;

	FString Test;

	for (auto& Name : RowNames)
	{
		FAfrikaansTable* Info = Tables[0]->FindRow<FAfrikaansTable>(Name, FString(""));
		if (Info->BookNumber == 1 && Info->Chapter == 1)
		{
			// EachBibles.Add(Info->Text);

			Test.Append(Info->Text + "\n");

			// UE_LOG(LogTemp, Warning, TEXT("%s : %s"), *Info->BookName, *Info->Text);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Test);
}
