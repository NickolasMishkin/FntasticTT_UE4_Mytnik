#include "TurtleBasePlayerController.h"
#include "Nest.h"

void ATurtleBasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAction("CreateTurtle1", IE_Pressed, this, &ATurtleBasePlayerController::SpawnTurtle1);
	InputComponent->BindAction("CreateTurtle2", IE_Pressed, this, &ATurtleBasePlayerController::SpawnTurtle2);
	InputComponent->BindAction("CreateTurtle3", IE_Pressed, this, &ATurtleBasePlayerController::SpawnTurtle3);
}

void ATurtleBasePlayerController::BeginPlay()
{
	FindAllActors(GetWorld(), NestOnScene);
}

void ATurtleBasePlayerController::SpawnTurtle1()
{
	for (auto CurrentNest : NestOnScene)
	{
		if (CurrentNest->Id == 1)
		{
			CurrentNest->SpawnTurtle();
		}
	}
}

void ATurtleBasePlayerController::SpawnTurtle2()
{
	for (auto CurrentNest : NestOnScene)
	{
		if (CurrentNest->Id == 2)
		{
			CurrentNest->SpawnTurtle();
		}
	}
}

void ATurtleBasePlayerController::SpawnTurtle3()
{
	for (auto CurrentNest : NestOnScene)
	{
		if (CurrentNest->Id == 3)
		{
			CurrentNest->SpawnTurtle();
		}
	}
}