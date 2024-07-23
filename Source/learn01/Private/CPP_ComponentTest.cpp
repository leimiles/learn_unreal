// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_ComponentTest.h"

// Sets default values for this component's properties
UCPP_ComponentTest::UCPP_ComponentTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCPP_ComponentTest::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hey I'm a component class"));
	LiftOrigin = GetOwner()->GetActorLocation();
	LiftTarget = LiftOrigin + FVector3d::UpVector * LiftOffset;
	// ...

	UE_LOG(LogTemp, Display, TEXT("LiftOrigin: %s"), *LiftOrigin.ToCompactString());
	UE_LOG(LogTemp, Display, TEXT("LiftTarget: %s"), *LiftTarget.ToCompactString());
}

// Called every frame
void UCPP_ComponentTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (LiftDuration > 0.0f)
	{
		LiftSpeed = FVector::Distance(LiftOrigin, LiftTarget) / LiftDuration;
	}
	else
	{
		LiftSpeed = 1.0f;
	}

	FVector NewPosition = FMath::VInterpConstantTo(GetOwner()->GetActorLocation(), LiftTarget, DeltaTime, LiftSpeed);
	GetOwner()->SetActorLocation(NewPosition);

	// UE_LOG(LogTemp, Warning, TEXT("My owner address: %u"), Owner);
	// UE_LOG(LogTemp, Warning, TEXT("My owner position: %s"), *(Owner->GetActorLocation().ToCompactString()));	// get value of FString

	// ...
}
