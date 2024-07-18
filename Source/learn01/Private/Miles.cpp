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
	InitPosition = GetActorLocation();
}

// Called every frame
void AMiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FFloat16 offset = sinf(GetGameTimeSinceCreation());
	// InitPosition.X += 0;
	//  how to print to screen, how to convert float to fstring
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::SanitizeFloat(offset));
	// how to print

	SetActorLocation(InitPosition);
}
