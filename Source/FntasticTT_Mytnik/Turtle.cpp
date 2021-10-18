#include "Turtle.h"
#include "Math/UnrealMathUtility.h"

ATurtle::ATurtle()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATurtle::SetStartPosition(FVector NewStartPosition)
{
	this->StartPosition = NewStartPosition;
}

void ATurtle::SetFinishPosition(FVector NewFinishPosition)
{
	this->FinishPosition = NewFinishPosition;
}

void ATurtle::SetMoveForwardTime(float NewMoveForwardTime)
{
	this->MoveForwardTime = NewMoveForwardTime;
}

void ATurtle::SetMoveBackTime(float NewMoveBackTime)
{
	this->MoveBackTime = NewMoveBackTime;
}

void ATurtle::SetStandTime(float NewStandTime)
{
	this->StandTime = NewStandTime;
}

void ATurtle::SetInputMovementMode(ETurtleMovementMode NewInputMovementMode)
{
	this->InputMovementMode = NewInputMovementMode;
}

void ATurtle::SetSpeed(float NewSpeed)
{
	this->Speed = NewSpeed;
}

void ATurtle::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	
	this->Movement();
}

bool ATurtle::IsCurrentMoveForwardTimeEnd()
{
	float DeltaSecond = GetWorld()->GetDeltaSeconds();
	CurrentMoveForwardTime += DeltaSecond;
	if (CurrentMoveForwardTime >= MoveForwardTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ATurtle::IsFinished()
{
	if (this->GetActorLocation() == FinishPosition) //Here I decided not to consider the probability of an error, since we are working with rather large dimensions
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurtle::InitTurtleValues(FVector InitStartPosition, FVector InitFinishPosition, float InitMoveForwardTime, float InitMoveBackTime, float InitStandTime, ETurtleMovementMode InitInputMovementMode, float InitSpeed)
{
	SetStartPosition(InitStartPosition);
	SetFinishPosition(InitFinishPosition);
	SetMoveForwardTime(InitMoveForwardTime);
	SetMoveBackTime(InitMoveBackTime);
	SetStandTime(InitStandTime);
	SetInputMovementMode(InitInputMovementMode);
	SetSpeed(InitSpeed);
	this->StartSpeed = InitSpeed;
}

void ATurtle::MoveForward()
{
	this->SetActorLocation(InterpolateVector(StartPosition, FinishPosition, {1.f, 1.f, 1.f}, Speed), true);
}

void ATurtle::MoveBack()
{
	this->SetActorLocation(InterpolateVector(this->GetActorLocation(), StartPosition, { 1.f, 1.f, 1.f }, Speed), true);
}

void ATurtle::MoveForwardBack()
{
	if (IsFinished())
	{
		return;
	}
	else
	{
		if (IsCurrentMoveForwardTimeEnd())
		{
			CurrentMoveBackTime += GetWorld()->GetDeltaSeconds();
			this->MoveBack();
			if (CurrentMoveBackTime >= MoveBackTime)
			{
				CurrentMoveForwardTime = 0.f;
				CurrentMoveBackTime = 0.f;
			}
		}
		else
		{
			this->MoveForward();
		}
	}
}

void ATurtle::MovementForward()
{
	if (IsFinished())
	{
		return;
	}
	else
	{
		MoveForward();
	}
}

void ATurtle::MoveForwardStand()
{
	if (IsFinished())
	{
		return;
	}
	else
	{
		if (IsCurrentMoveForwardTimeEnd())
		{
			CurrentStandTime += GetWorld()->GetDeltaSeconds();
			this->Speed = 0.f;
			if (CurrentStandTime >= StandTime)
			{
				CurrentMoveForwardTime = 0.f;
				CurrentStandTime = 0.f;
			}
		}
		else
		{
			this->Speed = this->StartSpeed;
			this->MoveForward();
		}
	}
}

void ATurtle::Movement()
{
	switch (InputMovementMode)
	{
	case ETurtleMovementMode::MoveForward:
		GetWorldTimerManager().SetTimer(TimerHandleClock, this, &ATurtle::MovementForward, 0.01f, true);
		break;
	case ETurtleMovementMode::MoveForwardStand:
		GetWorldTimerManager().SetTimer(TimerHandleClock, this, &ATurtle::MoveForwardStand, 0.01f, true);
		break;
	case ETurtleMovementMode::MoveForwardBack:
		GetWorldTimerManager().SetTimer(TimerHandleClock, this, &ATurtle::MoveForwardBack, 0.01f, true);
		break;
	}
}

FVector ATurtle::InterpolateVector(FVector VectorFrom, FVector VectorTo, FVector VectorError, float InterpSpeed)
{
	FVector ActorLocation = this->GetActorLocation();
	float DeltaTime = GetWorld()->GetDeltaSeconds();

	float InterpolateSpeedX = (abs(VectorTo.X - VectorFrom.X)/abs((VectorTo.X + VectorError.X) - ActorLocation.X) * InterpSpeed * 0.1f);
	float InterpolatedX = FMath::FInterpTo(ActorLocation.X, VectorTo.X, DeltaTime, InterpolateSpeedX);

	float InterpolateSpeedY = (abs(VectorTo.Y - VectorFrom.Y) / abs((VectorTo.Y + VectorError.Y) - ActorLocation.Y) * InterpSpeed * 0.1f);
	float InterpolatedY = FMath::FInterpTo(ActorLocation.Y, VectorTo.Y, DeltaTime, InterpolateSpeedY);

	float InterpolateSpeedZ = (abs(VectorTo.Z - VectorFrom.Z) / abs((VectorTo.Z + VectorError.Z) - ActorLocation.Z) * InterpSpeed * 0.1f);
	float InterpolatedZ = FMath::FInterpTo(ActorLocation.Z, VectorTo.Z, DeltaTime, InterpolateSpeedZ);

	return {InterpolatedX, InterpolatedY, InterpolatedZ};
}

