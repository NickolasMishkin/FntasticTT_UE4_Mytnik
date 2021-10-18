#include "Nest.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

ANest::ANest()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ANest::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANest::SpawnTurtle()
{
	ATurtle* Turtle = GetWorld()->SpawnActorDeferred<ATurtle>(TurtleClass, this->GetActorTransform());
	if (Turtle)
	{
		Turtle->InitTurtleValues(this->GetActorLocation(), TurtleFinishPointLocation, TurtleMoveForwardTime, TurtleMoveBackTime, TurtleStandTime, TurtleInputMovementMode, TurtleSpeed);
		UGameplayStatics::FinishSpawningActor(Turtle, this->GetActorTransform());
	}
}

void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

