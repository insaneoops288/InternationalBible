// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BibleContentUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INTERNATIONALBIBLE_API UBibleContentUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextBibleContent = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextBibleName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonTest = nullptr;

	UFUNCTION()
	void OnButtonTestClicked();

	/** 생성자에 해당하는 함수의 원형을 선언. */
	void NativeConstruct() override;
	/** Tick() 함수에 해당하는 함수의 원형을 선언. */
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
};
