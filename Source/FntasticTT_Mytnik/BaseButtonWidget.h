// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTT_MYTNIK_API UBaseButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, Category = "Ninja Turtles")
	FText LabelText;

	UPROPERTY(BlueprintReadOnly, Category = "Ninja Turtles", meta = (BindWidget))
	class UTextBlock* Label = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Ninja Turtles", meta = (BindWidget))
	class UButton* m_Button = nullptr;

};
