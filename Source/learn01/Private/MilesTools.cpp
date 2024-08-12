// Fill out your copyright notice in the Description page of Project Settings.

#include "MilesTools.h"
#include "Engine/GameEngine.h"

MilesTools::MilesTools()
{
    float a = 1.0f;
    float &aRef = a; // init a ref from a variable

    aRef = 3.0f; // to use ref, becuse we dont' want a copy of the value

    float *floatPtr = &aRef; // assign an address to a pointer
    *floatPtr = 5.0f;        // use pointer to change the value
}

MilesTools::~MilesTools()
{
}

void MilesTools::DebugOnScreen(const FString &Info, float TimeOfDisplay)
{
    FColor ColorOfDisplay = FColor::MakeRandomColor();
    GEngine->AddOnScreenDebugMessage(-1, TimeOfDisplay, ColorOfDisplay, Info);
}