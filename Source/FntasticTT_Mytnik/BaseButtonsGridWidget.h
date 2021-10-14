#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseButtonWidget.h"
#include "BaseButtonsGridWidget.generated.h"

//class UBaseButtonWidget;

UCLASS(Blueprintable)
class FNTASTICTT_MYTNIK_API UBaseButtonsGridWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, Category = "Ninja Turtles")
	TSubclassOf<UBaseButtonWidget> ButtonWidgetClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Ninja Turtles")
	int32 Columns = 3;

	UPROPERTY(BlueprintReadOnly, Category = "Ninja Turtles", meta = (BindWidget))
	class UUniformGridPanel* Grid = nullptr;

};
