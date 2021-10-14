// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseButtonWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"


void UBaseButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Label)
	{
		Label->SetText(LabelText);
	}

	m_Button = Cast<UButton>(GetWidgetFromName("m_Button"));
}


