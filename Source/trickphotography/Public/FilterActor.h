// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FilterableInterface.h"
#include "FilterActor.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class PPMHighlightType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	WallOutline = 2 UMETA(DisplayName = "Wall Outline"),
	HighlightPickup = 3 UMETA(DisplayName = "Highlight: Pickup"),
	HighlightHint = 4 UMETA(DisplayName = "Highlight: Hint")
};

UCLASS()
class TRICKPHOTOGRAPHY_API AFilterActor : public AActor, public IFilterableInterface
{
	GENERATED_BODY()
	
// public:	
// 	// Sets default values for this actor's properties
// 	AFilterActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<UActorComponent*> FilterableComponents;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Post Processing Highlight", Keywords = "Interact", Category = "Filter Actor"))
	void SetPPMHighlight(PPMHighlightType type);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Re-Register Filterable Components", Keywords = "Component", Category = "Filter Actor"))
	void RegisterFilterableComponents();

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
