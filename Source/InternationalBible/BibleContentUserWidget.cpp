// Fill out your copyright notice in the Description page of Project Settings.


#include "BibleContentUserWidget.h"
#include "InternationalBibleGameMode.h"
#include "Kismet/GameplayStatics.h"

/** TextBlock UI에 접근하기 위한 */
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UBibleContentUserWidget::OnButtonTestClicked()
{
	AInternationalBibleGameMode* GameMode = Cast<AInternationalBibleGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode->BibleIndex >= GameMode->Tables.Num())
		GameMode->BibleIndex = 0;

	FString BibleMessage = GameMode->GetBible(GameMode->BibleIndex, 1, 1);
	TextBibleContent->SetText(FText::FromString(BibleMessage));
	TextBibleContent->Font.Size = 50;

	// FString InternationalBibleName = GameMode->IntenationalBibles[GameMode->BibleIndex];
	TextBibleName->SetText(FText::FromString(GameMode->BibleName));

	GameMode->BibleIndex++;
}

void UBibleContentUserWidget::NativeConstruct()
{
	Super::NativeConstruct(); // 부모측의 함수의 내용을 모두 가져옴

	ButtonTest->OnClicked.AddDynamic(this, &UBibleContentUserWidget::OnButtonTestClicked);

	
}

void UBibleContentUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime); // 부모측의 함수의 내용을 모두 가져옴
}
