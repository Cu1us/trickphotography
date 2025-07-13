// Fill out your copyright notice in the Description page of Project Settings.

#include "FilterableStaticMeshActor.h"

// AFilterableStaticMeshActor::AFilterableStaticMeshActor(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
// {
//     UE_LOG(LogTemp, Warning, TEXT("Thing created!!!!"))
// }

void AFilterableStaticMeshActor::BeginPlay()
{
    Super::BeginPlay();

    HiddenDueToFilterSetting = false;
    DefaultMaterial = GetStaticMeshComponent()->GetMaterial(0);
    if (IsInvisible)
    {
        GetStaticMeshComponent()->SetVisibility(false);
        DefaultCollisionType = GetStaticMeshComponent()->GetCollisionObjectType();
        GetStaticMeshComponent()->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel4);
        GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
        GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);

        GetStaticMeshComponent()->bRenderCustomDepth = true;
        GetStaticMeshComponent()->CustomDepthStencilValue = 10;
        GetStaticMeshComponent()->MarkRenderStateDirty();
    }
}

// Any
void AFilterableStaticMeshActor::OnAnyPhoto_Implementation()
{
}
void AFilterableStaticMeshActor::OnAnyPhotoFinished_Implementation()
{
}

// Thermal
void AFilterableStaticMeshActor::OnThermalPhoto_Implementation()
{
    if (IsInvisible)
        return;
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, ThermalMaterial);
        break;
    case FilterVisibility::Hidden:
        if (GetStaticMeshComponent()->IsVisible())
        {
            GetStaticMeshComponent()->SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void AFilterableStaticMeshActor::OnThermalPhotoFinished_Implementation()
{
    if (IsInvisible)
        return;
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            GetStaticMeshComponent()->SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}

// UV
void AFilterableStaticMeshActor::OnUVPhoto_Implementation()
{
    if (IsInvisible)
        return;
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        if (IsValid(UVMaterial))
        {
            GetStaticMeshComponent()->SetMaterial(0, UVMaterial);
        }
        break;
    case FilterVisibility::Hidden:
        GetStaticMeshComponent()->SetVisibility(false);
        break;
    default:
        break;
    }
}
void AFilterableStaticMeshActor::OnUVPhotoFinished_Implementation()
{
    if (IsInvisible)
        return;
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        GetStaticMeshComponent()->SetVisibility(true);
        break;
    default:
        break;
    }
}

// X-Ray
void AFilterableStaticMeshActor::OnXrayPhoto_Implementation()
{
    if (IsInvisible)
        return;
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, XrayMaterial);
        break;
    case FilterVisibility::Hidden:
        if (GetStaticMeshComponent()->IsVisible())
        {
            GetStaticMeshComponent()->SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void AFilterableStaticMeshActor::OnXrayPhotoFinished_Implementation()
{
    if (IsInvisible)
        return;
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            GetStaticMeshComponent()->SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}

// Invisibility
void AFilterableStaticMeshActor::OnInvisPhoto_Implementation()
{
    if (IsInvisible)
    {
        GetStaticMeshComponent()->SetMaterial(0, InvisMaterial);
        GetStaticMeshComponent()->SetVisibility(true);
    }
}
void AFilterableStaticMeshActor::OnInvisPhotoFinished_Implementation()
{
    if (IsInvisible)
    {
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        GetStaticMeshComponent()->SetVisibility(false);
    }
}

void AFilterableStaticMeshActor::OnRevealFromInvisibility_Implementation()
{
    if (IsInvisible)
    {
        IsInvisible = false;
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        GetStaticMeshComponent()->SetVisibility(true);
        GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Ignore);
        GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
        GetStaticMeshComponent()->SetCollisionObjectType(DefaultCollisionType);

        GetStaticMeshComponent()->bRenderCustomDepth = false;
        GetStaticMeshComponent()->CustomDepthStencilValue = 0;
        GetStaticMeshComponent()->MarkRenderStateDirty();
    }
}
void AFilterableStaticMeshActor::MakeInvisible()
{
    if (!IsInvisible)
    {
        IsInvisible = true;
        GetStaticMeshComponent()->SetVisibility(false);
        DefaultCollisionType = GetStaticMeshComponent()->GetCollisionObjectType();
        GetStaticMeshComponent()->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel4);
        GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
        GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);

        GetStaticMeshComponent()->bRenderCustomDepth = true;
        GetStaticMeshComponent()->CustomDepthStencilValue = 10;
        GetStaticMeshComponent()->MarkRenderStateDirty();
    }
}