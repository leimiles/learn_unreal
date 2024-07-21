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
	UE_LOG(LogTemp, Display, TEXT("This is a log I want to show in log window.")); // output log to log window
	UE_LOG(LogTemp, Warning, TEXT("Current Move Range: %f"), MoveLimitY);		   // output log with parameters
}

// Called every frame
void AMiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FColor DebugTextColor = FColor::MakeRandomColor();
	FFloat16 DebugDisplayTime = 100.0f;
	FrameCount++;

	FFloat16 Offset = sinf(GetGameTimeSinceCreation() * MoveSpeed) * MoveLimitY;

	NewPosition.Y = CurrentPosition.Y + Offset;

	if (UseDebug)
	{
		GEngine->AddOnScreenDebugMessage(-1, DebugDisplayTime, DebugTextColor, "Current Frame = " + FString::FromInt(FrameCount));
		GEngine->AddOnScreenDebugMessage(-1, DebugDisplayTime, DebugTextColor, "Offset = " + FString::SanitizeFloat(Offset));
		GEngine->AddOnScreenDebugMessage(-1, DebugDisplayTime, DebugTextColor, "New Position = " + NewPosition.ToString());
	}

	SetActorLocation(NewPosition);
}
