// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/GameEngine.h"
#include "MilesTools.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

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

void UGrabber::ShowHitDebug()
{
	DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 20.0f, 12, FColor::Yellow, true); // ImpactPoint is the position where collision shape pivot hits
	DrawDebugSphere(GetWorld(), HitResult.Location, 20.0f, 12, FColor::Blue, true);		 // location is the position where collision shape surface hits
}

void UGrabber::ShowSweepSphereDebug(const FVector &StartPoint, const FVector &EndPoint, const float &SweepSize, const bool &IsHit)
{
	DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green);
	// DrawDebugSphere(GetWorld(), StartPoint, SweepSize, 16, FColor::Green);	// start point don't need show, camera start
	if (IsHit)
	{
		DrawDebugSphere(GetWorld(), EndPoint, SweepSize, 16, FColor::Red);
	}
	else
	{
		DrawDebugSphere(GetWorld(), EndPoint, SweepSize, 16, FColor::Green);
	}
	/*
	if (ShowDebug)
	{
		FVector DebugStart = GetComponentLocation();
		FVector DebugEnd = DebugStart + GetForwardVector() * MaxGrabLength; // remember to adjust component rotation
		DrawDebugLine(GetWorld(), DebugStart, DebugEnd, FColor::Green);

		FCollisionShape shape = FCollisionShape::MakeSphere(50.0f);
		FHitResult HitResult;
		bool IsHit = GetWorld()->SweepSingleByChannel(HitResult, DebugStart, DebugEnd, FQuat::Identity, ECC_GameTraceChannel1, shape); // emit a shape along the tracing line, see if any actor is being hit, and this hit is not collision hit

		DrawDebugSphere(GetWorld(), DebugStart, 50.0f, 32, FColor::Green);

		if (IsHit)
		{
			DrawDebugSphere(GetWorld(), DebugEnd, 50.0f, 32, FColor::Red);
		}
		else
		{
			DrawDebugSphere(GetWorld(), DebugEnd, 50.0f, 32, FColor::Green);
		}
	}
	*/
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// FString RotatorInfo = GetComponentRotation().ToCompactString();
	// MilesTools::DebugOnScreen("Rotator Pitch = " + FString::SanitizeFloat(ComponentRotator.Pitch) + ", Yaw = " + FString::SanitizeFloat(ComponentRotator.Yaw));
	// MilesTools::DebugOnScreen(RotatorInfo);
	// ...

	// UWorld *MyWorld = GetWorld();
	// MilesTools::DebugOnScreen(FString::SanitizeFloat(MyWorld->TimeSeconds)); // print seconds since game starts

	// MilesTools::DebugOnScreen(DebugEnd.ToCompactString());

	// SubtractLife(LifeCount);
	// MilesTools::DebugOnScreen(FString::FromInt(LifeCount));

	// ShowDebugLine();

	FVector SweepStart = GetComponentLocation();
	FVector SweepEnd = SweepStart + GetForwardVector() * MaxGrabLength;
	FCollisionShape CollisionShape = FCollisionShape::MakeSphere(MaxSweepSize);
	bool IsHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		SweepStart,
		SweepEnd,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		CollisionShape);

	if (IsHit)
	{
		ActorGrabbed = HitResult.GetActor();
		SweepEnd = SweepStart + GetForwardVector() * HitResult.Distance;

		// MilesTools::DebugOnScreen("Location = " + HitResult.Location.ToCompactString());
		// MilesTools::DebugOnScreen("ImpactPoint = " + HitResult.ImpactPoint.ToCompactString());
	}
	else
	{
		ActorGrabbed = nullptr;
	}

	if (ShowDebug)
	{
		ShowSweepSphereDebug(SweepStart, SweepEnd, MaxSweepSize, IsHit);
	}
}

void UGrabber::Release()
{
	MilesTools::DebugOnScreen("yeah");
}

void UGrabber::Grab()
{
	if (ActorGrabbed != nullptr)
	{
		MilesTools::DebugOnScreen(ActorGrabbed->GetActorNameOrLabel());
		UPhysicsHandleComponent *PhysicsHandle = ActorGrabbed->FindComponentByClass<UPhysicsHandleComponent>();

		if (PhysicsHandle != nullptr)
		{
			MilesTools::DebugOnScreen(PhysicsHandle->GetName());
		}

		ShowHitDebug();
	}
}
