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
    afri,
    albanian,
    almeida_ra,
    almeida_rc,
    asv,
    bishops,
    bkr,
    blivre,
    bungo,
    cadman,
    chinese_union_simp,
    chinese_union_trad,
    ckjv_sds,
    ckjv_sdt,
    cornilescu,
    coverdale,
    diodati,
    elberfelder_1871,
    elberfelder_1905,
    epee,
    fidela,
    finn,
    geneva,
    indo_tb,
    indo_tm,
    karoli,
    kjv,
    kougo,
    luther,
    luther_1912,
    maori,
    martin,
    net,
    oster,
    pol_nbg,
    pol_ubg,
    polbg,
    rv_1909,
    rvg,
    rvg_2004,
    sagradas,
    schlachter,
    segond_1910,
    stve,
    synodal,
    tagab,
    turkish,
    tyndale,
    web,
};

UCLASS(minimalapi)
class AInternationalBibleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInternationalBibleGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bible")
	TArray<class UDataTable*> Tables;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bible")
    class UDataTable* OldTestamentTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bible")
    class UDataTable* NewTestamentTable;

	virtual void BeginPlay() override;

	// TMap<FString, FString> IntenationalBibles;
	TArray<FString> IntenationalBibles;

	FString GetBible(int32 Index, int32 BookNumber, int32 Chapter);

	TArray<FString> GetBibles(int32 Index, int32 BookNumber, int32 Chapter);

	int32 BibleIndex;
	FString BibleName;
};



