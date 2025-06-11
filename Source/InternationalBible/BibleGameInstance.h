// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Engine/DataTable.h"

#include "BibleGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FAfrikaansTable : public FTableRowBase
{
public:
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItem")
	FString BookName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItem")
	int32 BookNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItem")
	int32 Chapter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItem")
	int32 Verse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItem")
	FString Text;
};

/**
 * 
 */
UCLASS()
class INTERNATIONALBIBLE_API UBibleGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
};
