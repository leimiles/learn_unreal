// Fill out your copyright notice in the Description page of Project Settings.

#include "Miles.h"

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
	MyX = MyPos.Y;
}

// Called every frame
void AMiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
