// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Math/Transform.h"
#include "PickupableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UPickupableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class TRICKPHOTOGRAPHY_API IPickupableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnPickup(bool isCammy);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnDrop(bool isCammy);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	bool CanBePickedUp(bool isCammy);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Activate(FTransform cameraTransform, bool isCammy);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	FString GetPickupID();
};
