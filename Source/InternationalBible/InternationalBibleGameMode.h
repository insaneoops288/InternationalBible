// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InternationalBibleGameMode.generated.h"

UCLASS(minimalapi)
class AInternationalBibleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInternationalBibleGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bible")
	TArray<class UDataTable*> Tables;
	virtual void BeginPlay() override;
};



