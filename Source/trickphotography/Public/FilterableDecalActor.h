// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "FilterableInterface.h"
#include "FilterableDecalActor.generated.h"

/**
 * 
 */
UCLASS()
class TRICKPHOTOGRAPHY_API AFilterableDecalActor : public ADecalActor, public IFilterableInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleByPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleInThermal;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleInUV;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleInXray;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool AlwaysShowInEditor = true;

	//void OnAnyPhoto_Implementation() override;
	void OnAnyPhotoFinished_Implementation() override;
	void OnThermalPhoto_Implementation() override;
	//void OnThermalPhotoFinished_Implementation() override;
	void OnUVPhoto_Implementation() override;
	//void OnUVPhotoFinished_Implementation() override;
	void OnXrayPhoto_Implementation() override;
	//void OnXrayPhotoFinished_Implementation() override;

	void OnConstruction(const FTransform &Transform) override;
};
