// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FilterableInterface.h"
#include "FilterPawn.generated.h"

UCLASS()
class TRICKPHOTOGRAPHY_API AFilterPawn : public APawn, public IFilterableInterface
{
	GENERATED_BODY()

	// public:
	//  Sets default values for this pawn's properties
	// AFilterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<UActorComponent *> FilterableComponents;

public:
	void OnAnyPhoto_Implementation() override;
	void OnAnyPhotoFinished_Implementation() override;
	void OnThermalPhoto_Implementation() override;
	void OnThermalPhotoFinished_Implementation() override;
	void OnUVPhoto_Implementation() override;
	void OnUVPhotoFinished_Implementation() override;
	void OnXrayPhoto_Implementation() override;
	void OnXrayPhotoFinished_Implementation() override;
	void OnInvisPhoto_Implementation() override;
	void OnInvisPhotoFinished_Implementation() override;
	void OnRevealFromInvisibility_Implementation() override;
};
