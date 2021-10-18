#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turtle.generated.h"

UENUM(BlueprintType)
enum class ETurtleMovementMode : uint8
{
	none = 0	UMETA(DisplayName = "none"),
	MoveForward = 1		UMETA(DisplayName = "MoveForward"),
	MoveForwardBack = 2		UMETA(DisplayName = "MoveForwardBack"),
	MoveForwardStand = 3	 UMETA(DisplayName = "MoveForwardStand"),
};

UCLASS()
class FNTASTICTT_MYTNIK_API ATurtle : public AActor
{
	GENERATED_BODY()
	
protected:

	float CurrentMoveForwardTime;
	float CurrentMoveBackTime;
	float CurrentStandTime;
	float StartSpeed;

public:	

	ATurtle();

	UFUNCTION(BlueprintCallable)
	void SetStartPosition(FVector NewStartPosition);

	UFUNCTION(BlueprintCallable)
	void SetFinishPosition(FVector NewFinishPosition);

	UFUNCTION(BlueprintCallable)
	void SetMoveForwardTime(float NewMoveForwardTime);

	UFUNCTION(BlueprintCallable)
	void SetMoveBackTime(float NewMoveBackTime);

	UFUNCTION(BlueprintCallable)
	void SetStandTime(float NewStandTime);

	UFUNCTION(BlueprintCallable)
	void SetInputMovementMode(ETurtleMovementMode NewInputMovementMode);

	UFUNCTION(BlueprintCallable)
	void SetSpeed(float NewSpeed);

	UFUNCTION(BlueprintCallable)
	void Movement();

	FVector InterpolateVector(FVector VectorFrom, FVector VectorTo, FVector VectorError, float InterpSpeed);

	virtual void Tick(float DeltaTime) override;

	void InitTurtleValues(FVector InitStartPosition, FVector InitFinishPosition, float InitMoveForwardTime, float InitMoveBackTime, float InitStandTime, ETurtleMovementMode InitInputMovementMode, float InitSpeed);

protected:

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void BeginPlay() override;

	bool IsCurrentMoveForwardTimeEnd();

	bool IsFinished();

public:	

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	FVector StartPosition;

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	FVector FinishPosition;

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	float MoveForwardTime;

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	float MoveBackTime;

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	float StandTime;

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	ETurtleMovementMode InputMovementMode;

	UPROPERTY(BlueprintReadOnly, Category = "Nest")
	float Speed;

private:

	void MoveForward();

	void MoveBack();

	void MoveForwardBack();
	
	void MovementForward();

	void MoveForwardStand();

private:

	FTimerHandle TimerHandleClock;
};
