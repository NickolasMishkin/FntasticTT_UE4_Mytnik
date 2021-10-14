// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseButtonsGridWidget.h"
#include "Components/UniformGridPanel.h"

void UBaseButtonsGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Grid && ButtonWidgetClass)
	{
		Grid->ClearChildren();

		for (int32 x = 0; x < Columns; ++x)
		{
			UBaseButtonWidget* Widget = CreateWidget<UBaseButtonWidget>(GetWorld(), ButtonWidgetClass);
			if (Widget)
			{
				Grid->AddChildToUniformGrid(Widget,0,x);
			}
		}
	}
}
