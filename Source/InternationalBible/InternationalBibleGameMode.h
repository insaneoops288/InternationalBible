// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InternationalBibleGameMode.generated.h"

UENUM()
enum class EBibleType
{
	None = -1,
	OldTestament,
	NewTestament,
	Max,
};

UENUM()
enum class EOldTestamentType
{
    None = -1,
    Genesis,
    Exodus,
    Leviticus,
    Numbers,
    Deuteronomy,
    Joshua,
    Judges,
    Ruth,
    Samuel1,
    Samuel2,
    Kings1,
    Kings2,
    Chronicles1,
    Chronicles2,
    Ezra,
    Nehemiah,
    Esther,
    Job,
    Psalms,
    Proverbs,
    Ecclesiastes,
    SongOfSongs,
    Isaiah,
    Jeremiah,
    Lamentations,
    Ezekiel,
    Daniel,
    Hosea,
    Joel,
    Amos,
    Obadiah,
    Jonah,
    Micah,
    Nahum,
    Habakkuk,
    Zephaniah,
    Haggai,
    Zechariah,
    Malachi,
    Max,
};

UENUM()
enum class ENewTestamentType
{
    None = -1,
    Matthew,
    Mark,
    Luke,
    John,
    Acts,
    Romans,
    Corinthians1,
    Corinthians2,
    Galatians,
    Ephesians,
    Philippians,
    Colossians,
    Thessalonians1,
    Thessalonians2,
    Timothy1,
    Timothy2,
    Titus,
    Philemon,
    Hebrews,
    James,
    Peter1,
    Peter2,
    John1,
    John2,
    John3,
    Jude,
    Revelation,
    Max,
};

UENUM()
enum class EBibleCountryType
{
	None = -1,
	AAA,
	// AAA,
};

UCLASS(minimalapi)
class AInternationalBibleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInternationalBibleGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bible")
	TArray<class UDataTable*> Tables;
	virtual void BeginPlay() override;

	// TMap<FString, FString> IntenationalBibles;
	TArray<FString> IntenationalBibles;

	FString GetBible(int32 Index, int32 BookNumber, int32 Chapter);

	TArray<FString> GetBibles(int32 Index, int32 BookNumber, int32 Chapter);

	int32 BibleIndex;
	FString BibleName;
};



