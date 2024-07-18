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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float MoveLimitX; // 0.0 by default
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f; // 0.0 by default
	UPROPERTY(EditAnywhere)
	FVector InitPosition; // 0.0 by default
};
