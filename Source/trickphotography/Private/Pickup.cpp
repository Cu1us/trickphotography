// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"

void APickup::BeginPlay()
{
    Super::BeginPlay();
    PhysicsSimulatedComponents.Empty();
    for (UActorComponent *component : GetComponents())
    {
        UPrimitiveComponent *primitiveComp = Cast<UPrimitiveComponent>(component);
        if (primitiveComp)
        {
            if (primitiveComp->IsSimulatingPhysics())
            {
                PhysicsSimulatedComponents.Add(primitiveComp);
            }
        }
    }
}

void APickup::OnPickup_Implementation(bool isCammy)
{
    for (UPrimitiveComponent *component : PhysicsSimulatedComponents)
    {
        component->SetSimulatePhysics(false);
        component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }
}

void APickup::OnDrop_Implementation(bool isCammy)
{
    for (UPrimitiveComponent *component : PhysicsSimulatedComponents)
    {
        component->SetSimulatePhysics(true);
        component->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    }
}

bool APickup::CanBePickedUp_Implementation(bool isCammy)
{
    return true;
}

FString APickup::GetPickupID_Implementation()
{
    return PickupID;
}