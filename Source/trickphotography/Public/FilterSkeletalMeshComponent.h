// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "FilterableInterface.h"
#include "FilterableStaticMeshActor.h"
#include "FilterSkeletalMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Filterable), meta = (BlueprintSpawnableComponent))
class TRICKPHOTOGRAPHY_API UFilterSkeletalMeshComponent : public USkeletalMeshComponent, public IFilterableInterface
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UMaterialInterface *DefaultMaterial;
	ECollisionChannel DefaultCollisionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|Thermal")
	FilterVisibility ThermalInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|Thermal")
	UMaterialInterface *ThermalMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|UV")
	FilterVisibility UVInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|UV")
	UMaterialInterface *UVMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|X-Ray")
	FilterVisibility XrayInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|X-Ray")
	UMaterialInterface *XrayMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|Invisibility")
	bool IsInvisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials\|Invisibility")
	UMaterialInterface *InvisMaterial;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Make Invisible", Keywords = "Invisibility", Category = "Filter Interaction"))
	void MakeInvisible();
	
	UFUNCTION(BlueprintCallable, Category = "Filter Interaction")
	void SetMainMaterial(UMaterialInterface *NewMaterial);
	
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

private:
	bool HiddenDueToFilterSetting;
};
