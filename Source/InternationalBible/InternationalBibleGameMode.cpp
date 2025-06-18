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

	BibleIndex = 0;

	IntenationalBibles.Empty();
	IntenationalBibles.Add(TEXT("afri"), TEXT("Afrikaans 1953 (1953)"));
	IntenationalBibles.Add(TEXT("albanian"), TEXT("Albanian"));
	IntenationalBibles.Add(TEXT("almeida_ra"), TEXT("Tradução de João Ferreira de Almeida (Versão Revista e Atualizada)"));
	IntenationalBibles.Add(TEXT("almeida_rc"), TEXT("Tradução de João Ferreira de Almeida Revista e Corrigida."));
	IntenationalBibles.Add(TEXT("asv"), TEXT("American Standard Version (1901)"));
	IntenationalBibles.Add(TEXT("asvs"), TEXT("American Standard Version w Strong's"));
	IntenationalBibles.Add(TEXT("bishops"), TEXT("Bishops Bible (1568)"));
	IntenationalBibles.Add(TEXT("bkr"), TEXT("Bible Kralicka"));
	IntenationalBibles.Add(TEXT("blivre"), TEXT("Biblia Livre"));
	IntenationalBibles.Add(TEXT("bungo"), TEXT("Bungo-yaku: Taisho-kaiyaku (NT) (1950), Meiji-yaku (OT) (1953) (1950/1953)"));
	IntenationalBibles.Add(TEXT("cadman"), TEXT("Vietnamese Cadman (1934)"));
	IntenationalBibles.Add(TEXT("chinese_union_simp"), TEXT("Chinese Union (Simplified)"));
	IntenationalBibles.Add(TEXT("chinese_union_trad"), TEXT("Chinese Union (Traditional)"));
	IntenationalBibles.Add(TEXT("ckjv_sds"), TEXT("中文英皇钦定本上帝版 Chinese KJV (Simplified) Shang-Di 简体中文"));
	IntenationalBibles.Add(TEXT("ckjv_sdt"), TEXT("中文英皇欽定本上帝版 Chinese KJV (Traditional) Shang-Di 繁體中文"));
	IntenationalBibles.Add(TEXT("cornilescu"), TEXT("Cornilescu"));
	IntenationalBibles.Add(TEXT("coverdale"), TEXT("Coverdale Bible (1535)"));
	IntenationalBibles.Add(TEXT("diodati"), TEXT("Diodati (1649)"));
	IntenationalBibles.Add(TEXT("elberfelder_1871"), TEXT("Elberfelder (1871)"));
	IntenationalBibles.Add(TEXT("elberfelder_1905"), TEXT("Elberfelder (1905)"));
	IntenationalBibles.Add(TEXT("epee"), TEXT("La Bible de l'Épée (2005)"));
	IntenationalBibles.Add(TEXT("fidela"), TEXT("Fidela Biblia în limba română (2011-2016)"));
	IntenationalBibles.Add(TEXT("finn"), TEXT("Finnish 1776 (Finnish) (1776)"));
	IntenationalBibles.Add(TEXT("geneva"), TEXT("Geneva Bible (1587)"));
	IntenationalBibles.Add(TEXT("indo_tb"), TEXT("Terjemahan Baru (1994)"));
	IntenationalBibles.Add(TEXT("indo_tm"), TEXT("Terjemahan Lama"));
	IntenationalBibles.Add(TEXT("irv"), TEXT("Indian Revised Version (2017 / 2018)"));
	IntenationalBibles.Add(TEXT("karoli"), TEXT("Karoli"));
	IntenationalBibles.Add(TEXT("kjv"), TEXT("Authorized King James Version (1611 / 1769)"));
	IntenationalBibles.Add(TEXT("kougo"), TEXT("Kougo-yaku (1954/1955)"));
	IntenationalBibles.Add(TEXT("luther"), TEXT("Luther Bible (1545) (1545)"));
	IntenationalBibles.Add(TEXT("luther_1912"), TEXT("Luther Bible (1912) (1912)"));
	IntenationalBibles.Add(TEXT("maori"), TEXT("Maori Bible"));
	IntenationalBibles.Add(TEXT("martin"), TEXT("Martin (1744)"));
	IntenationalBibles.Add(TEXT("net"), TEXT("NET Bible® (1996-2016)"));
	IntenationalBibles.Add(TEXT("oster"), TEXT("Ostervald (1996)"));
	IntenationalBibles.Add(TEXT("pol_nbg"), TEXT("NOWEJ BIBLII GDANSKIEJ (2012)"));
	IntenationalBibles.Add(TEXT("pol_ubg"), TEXT("Uwspółcześniona Biblia Gdańska (2017)"));
	IntenationalBibles.Add(TEXT("polbg"), TEXT("Polska Biblia Gdanska (1881)"));
	IntenationalBibles.Add(TEXT("rv_1858"), TEXT("Reina Valera 1858 NT (1858)"));
	IntenationalBibles.Add(TEXT("rv_1909"), TEXT("Reina Valera 1909 (1909)"));
	IntenationalBibles.Add(TEXT("rvg"), TEXT("Reina Valera Gómez (2010)"));
	IntenationalBibles.Add(TEXT("rvg_2004"), TEXT("Reina Valera Gómez (2004) (2004)"));
	IntenationalBibles.Add(TEXT("sagradas"), TEXT("Sagradas Escrituras (1569)"));
	IntenationalBibles.Add(TEXT("schlachter"), TEXT("Schlachter Bibel (1951)"));
	IntenationalBibles.Add(TEXT("segond_1910"), TEXT("Louis Segond 1910 (1910"));
	IntenationalBibles.Add(TEXT("stve"), TEXT("Staten Vertaling"));
	IntenationalBibles.Add(TEXT("swahili"), TEXT("Swahili NT"));
	IntenationalBibles.Add(TEXT("synodal"), TEXT("Synodal (1876)"));
	IntenationalBibles.Add(TEXT("tagab"), TEXT("Tagalog Ang Biblia (1905)"));
	IntenationalBibles.Add(TEXT("thaikjv"), TEXT("Thai KJV"));
	IntenationalBibles.Add(TEXT("tr"), TEXT("Textus Receptus NT (1550 / 1884)"));
	IntenationalBibles.Add(TEXT("trparsed"), TEXT("Textus Receptus Parsed NT (1550 / 1884)"));
	IntenationalBibles.Add(TEXT("turkish"), TEXT("Turkish"));
	IntenationalBibles.Add(TEXT("tyndale"), TEXT("Tyndale Bible"));
	IntenationalBibles.Add(TEXT("web"), TEXT("World English Bible (2006)"));
	IntenationalBibles.Add(TEXT("wlc"), TEXT("WLC"));
}

void AInternationalBibleGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true; //마우스 관련 처리, 컨트롤러
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;

	// GetBible(28, 1, 1);
}

FString AInternationalBibleGameMode::GetBible(int32 Index, int32 BookNumber, int32 Chapter)
{
	UDataTable* SelectedTable = Tables[Index];
	BibleName = SelectedTable->GetName();

	TArray<FName> RowNames = SelectedTable->GetRowNames();

	FString ColectStrings;

	for (auto& Key : RowNames)
	{
		FAfrikaansTable* Info = SelectedTable->FindRow<FAfrikaansTable>(Key, FString(""));
		if (Info->BookNumber == BookNumber && Info->Chapter == Chapter)
		{
			ColectStrings.Append(Info->Text + "\n\n");
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
