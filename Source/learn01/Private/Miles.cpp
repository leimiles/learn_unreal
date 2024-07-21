// Fill out your copyright notice in the Description page of Project Settings.

#include "Miles.h"
#include "Engine/GameEngine.h" // in order to print log to screen

// Sets default values
AMiles::AMiles()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMiles::BeginPlay()
{
	Super::BeginPlay();
	CurrentPosition = GetActorLocation();
	FrameCount = 0;
	NewPosition = CurrentPosition;
	FString ActorName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("This is a log I want to show in log window.")); // output log to log window
	UE_LOG(LogTemp, Warning, TEXT("Current Move Range: %f"), MoveLimitY);		   // output log with parameters
	UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *ActorName);				   // use FString var with pointer
}

// Called every frame
void AMiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	float Offset;
	SwingMove(&Offset);
	*/
	SwingMove();
	Rotate(DeltaTime);
	DebugMoveInfo();
}

/*
void AMiles::SwingMove(float *offset) // default parameter won't need default value
{
	*offset = sinf(GetGameTimeSinceCreation() * MoveSpeed) * MoveLimitY;
	NewPosition.Y = CurrentPosition.Y + *offset;
	SetActorLocation(NewPosition);
}
*/

void AMiles::SwingMove()
{
	Offset = sinf(GetGameTimeSinceCreation() * MoveSpeed) * MoveLimitY;
	NewPosition.Y = CurrentPosition.Y + Offset;
	SetActorLocation(NewPosition);
}

void AMiles::DebugMoveInfo()
{
	if (UseDebug)
	{
		FrameCount++;
		DebugTextColor = FColor::MakeRandomColor();
		GEngine->AddOnScreenDebugMessage(-1, DebugDisplayTime, DebugTextColor, "Current Frame = " + FString::FromInt(FrameCount));
		GEngine->AddOnScreenDebugMessage(-1, DebugDisplayTime, DebugTextColor, "Offset = " + FString::SanitizeFloat(Offset));
		GEngine->AddOnScreenDebugMessage(-1, DebugDisplayTime, DebugTextColor, "New Position = " + NewPosition.ToString());
	}
}

void AMiles::PureFunction() const
{
	FString Message = "Hey, wazzup?";
	UE_LOG(LogTemp, Display, TEXT("Your message %s"), *Message);
}

void AMiles::Rotate(float deltaTime)
{
	AddActorLocalRotation(RotationSpeed * deltaTime);
}
