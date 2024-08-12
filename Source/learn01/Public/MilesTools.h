// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class LEARN01_API MilesTools
{
public:
	MilesTools();
	~MilesTools();
	static void DebugOnScreen(const FString &Info, float TimeOfDisplay = 3.0f);
};
