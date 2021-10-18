#pragma once

#include "CoreMinimal.h"
#include "Turtle.h"
#include "GameFramework/Actor.h"
#include "Nest.generated.h"

UCLASS()
class FNTASTICTT_MYTNIK_API ANest : public AActor
{
	GENERATED_BODY()
	
public:	

	ANest();

	UPROPERTY(EditAnywhere, Category = "Turtle")
	unsigned int Id = 1;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	FVector TurtleFinishPointLocation;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	TSubclassOf<ATurtle> TurtleClass;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	float TurtleMoveForwardTime;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	float TurtleMoveBackTime;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	float TurtleStandTime;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	ETurtleMovementMode TurtleInputMovementMode;

	UPROPERTY(EditAnywhere, Category = "Turtle")
	float TurtleSpeed;

protected:

	virtual void BeginPlay() override;

public:	

	void SpawnTurtle();

	virtual void Tick(float DeltaTime) override;

};
