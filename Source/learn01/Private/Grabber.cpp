// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/GameEngine.h"
#include "MilesTools.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FString RotatorInfo = GetComponentRotation().ToCompactString();
	// MilesTools::DebugOnScreen("Rotator Pitch = " + FString::SanitizeFloat(ComponentRotator.Pitch) + ", Yaw = " + FString::SanitizeFloat(ComponentRotator.Yaw));
	// MilesTools::DebugOnScreen(RotatorInfo);
	// ...

	// UWorld *MyWorld = GetWorld();
	// MilesTools::DebugOnScreen(FString::SanitizeFloat(MyWorld->TimeSeconds)); // print seconds since game starts

	FVector DebugStart = GetComponentLocation();
	FVector DebugEnd = DebugStart + GetForwardVector() * MaxGrabLength; // remember to adjust component rotation
	DrawDebugLine(GetWorld(), DebugStart, DebugEnd, FColor::Green);

	// MilesTools::DebugOnScreen(DebugEnd.ToCompactString());
}
