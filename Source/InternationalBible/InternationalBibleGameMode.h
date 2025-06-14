// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InternationalBibleGameMode.generated.h"

UENUM()
enum class EBibleType
{
	None = -1,
	AAA,
	AAA,
};

UENUM()
enum class EBibleCountryType
{
	None = -1,
	AAA,
	AAA,
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

	FString GetBible(int32 Index, int32 BookNumber, int32 Chapter);

	TArray<FString> GetBibles(int32 Index, int32 BookNumber, int32 Chapter);
};



