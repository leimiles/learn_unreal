// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Miles.generated.h"

UCLASS()
class LEARN01_API AMiles : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector CurrentPosition;
	int32 FrameCount = 0;
	FVector NewPosition;
	FFloat16 DebugDisplayTime = 100.0f;
	FColor DebugTextColor;
	FFloat16 Offset = 0.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	bool UseDebug = false;
	UPROPERTY(EditAnywhere)
	float MoveLimitY = 0.0f;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
	FRotator RotationSpeed;
	// void SwingMove(float *offset = nullptr);
	void SwingMove();
	void Rotate(float deltaTime);
	void DebugMoveInfo();

	void PureFunction() const; // const function means this function can't change anything about this class
};
