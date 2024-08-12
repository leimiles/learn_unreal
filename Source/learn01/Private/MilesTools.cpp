// Fill out your copyright notice in the Description page of Project Settings.

#include "MilesTools.h"
#include "Engine/GameEngine.h"

MilesTools::MilesTools()
{
}

MilesTools::~MilesTools()
{
}

void MilesTools::DebugOnScreen(const FString &Info, float TimeOfDisplay)
{
    FColor ColorOfDisplay = FColor::MakeRandomColor();
    GEngine->AddOnScreenDebugMessage(-1, TimeOfDisplay, ColorOfDisplay, Info);
}