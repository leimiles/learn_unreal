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

void UGrabber::SubtractLife(uint8 &Life) // no copy, just change the value
{
	if (Life > 0)
	{
		Life--;
	}
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

	// SubtractLife(LifeCount);
	// MilesTools::DebugOnScreen(FString::FromInt(LifeCount));
	FCollisionShape shape = FCollisionShape::MakeSphere(50.0f);
	FHitResult HitResult;
	bool IsHit = GetWorld()->SweepSingleByChannel(HitResult, DebugStart, DebugEnd, FQuat::Identity, ECC_GameTraceChannel1, shape); // emit a shape along the tracing line, see if any actor is being hit, and this hit is not collision hit

	if (IsHit)
	{
		MilesTools::DebugOnScreen(HitResult.GetActor()->GetActorNameOrLabel());	// this Actor is the first actor the sphere tracing hits
		DrawDebugSphere(GetWorld(), DebugStart, 50.0f, 32, FColor::Green);
		DrawDebugSphere(GetWorld(), DebugEnd, 50.0f, 32, FColor::Green);
	}
}
