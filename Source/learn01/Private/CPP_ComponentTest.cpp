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

	// ...
}

// Called every frame
void UCPP_ComponentTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor *Owner = GetOwner();

	UE_LOG(LogTemp, Warning, TEXT("My owner address: %u"), Owner);
	UE_LOG(LogTemp, Warning, TEXT("My owner position: %s"), *(Owner->GetActorLocation().ToString()));	// get value of FString

	// ...
}
