// Fill out your copyright notice in the Description page of Project Settings.


#include "FilterableDecalActor.h"
#include "Components/DecalComponent.h"

void AFilterableDecalActor::BeginPlay()
{
    Super::BeginPlay();
    GetDecal()->SetVisibility(VisibleByPlayer);
}

void AFilterableDecalActor::OnAnyPhotoFinished_Implementation()
{
    GetDecal()->SetVisibility(VisibleByPlayer);
}

void AFilterableDecalActor::OnThermalPhoto_Implementation()
{
    GetDecal()->SetVisibility(VisibleInThermal);
}

void AFilterableDecalActor::OnUVPhoto_Implementation()
{
    GetDecal()->SetVisibility(VisibleInUV);
}

void AFilterableDecalActor::OnXrayPhoto_Implementation()
{
    GetDecal()->SetVisibility(VisibleInXray);
}

void AFilterableDecalActor::OnConstruction(const FTransform &Transform)
{
    Super::OnConstruction(Transform);
    GetDecal()->SetVisibility(VisibleByPlayer || AlwaysShowInEditor);
}