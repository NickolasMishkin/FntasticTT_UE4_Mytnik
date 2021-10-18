// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "TurtleBasePlayerController.generated.h"

template<typename T>
void FindAllActors(UWorld* World, TArray<T*>& Out)
{
	for (TActorIterator<T> It(World); It; ++It)
	{
		Out.Add(*It);
	}
}

UCLASS()
class FNTASTICTT_MYTNIK_API ATurtleBasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	TArray<class ANest*> NestOnScene;

public:
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

protected:

	void SpawnTurtle1();

	void SpawnTurtle2();
	
	void SpawnTurtle3();
};
