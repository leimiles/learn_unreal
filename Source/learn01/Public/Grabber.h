// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LEARN01_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void SubtractLife(uint8 &LifeCount);

private:
	void ShowSweepSphereDebug(const FVector &StartPoint, const FVector &EndPoint, const float &SweepSize, const bool &IsHit = false);
	AActor *ActorGrabbed = nullptr;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
	float MaxGrabLength = 200.0f;
	UPROPERTY(EditAnywhere)
	float MaxSweepSize = 20.0f;

	UPROPERTY(EditAnywhere)
	uint8 LifeCount = 3;

	UPROPERTY(EditAnywhere)
	bool ShowDebug = false;

	UFUNCTION(BlueprintCallable)
	void Release();
	UFUNCTION(BlueprintCallable)
	void Grab();
};
