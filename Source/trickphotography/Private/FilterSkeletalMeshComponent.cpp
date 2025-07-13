// Fill out your copyright notice in the Description page of Project Settings.


#include "FilterSkeletalMeshComponent.h"

void UFilterSkeletalMeshComponent::SetMainMaterial(UMaterialInterface *NewMaterial)
{
    DefaultMaterial = NewMaterial;
    SetMaterial(0, NewMaterial);
}
void UFilterSkeletalMeshComponent::BeginPlay()
{
    Super::BeginPlay();

    HiddenDueToFilterSetting = false;

    DefaultMaterial = GetMaterial(0);

    if (IsInvisible)
    {
        SetVisibility(false);
        DefaultCollisionType = GetCollisionObjectType();
        SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel4);
        SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
        SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);

        bRenderCustomDepth = true;
        CustomDepthStencilValue = 10;
        MarkRenderStateDirty();
    }
}

// Any
void UFilterSkeletalMeshComponent::OnAnyPhoto_Implementation()
{
}
void UFilterSkeletalMeshComponent::OnAnyPhotoFinished_Implementation()
{
}

// Thermal
void UFilterSkeletalMeshComponent::OnThermalPhoto_Implementation()
{
    if (IsInvisible)
        return;
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, ThermalMaterial);
        break;
    case FilterVisibility::Hidden:
        if (IsVisible())
        {
            SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void UFilterSkeletalMeshComponent::OnThermalPhotoFinished_Implementation()
{
    if (IsInvisible)
        return;
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}

// UV
void UFilterSkeletalMeshComponent::OnUVPhoto_Implementation()
{
    if (IsInvisible)
        return;
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        if (IsValid(UVMaterial))
        {
            SetMaterial(0, UVMaterial);
        }
        break;
    case FilterVisibility::Hidden:
        SetVisibility(false);
        break;
    default:
        break;
    }
}
void UFilterSkeletalMeshComponent::OnUVPhotoFinished_Implementation()
{
    if (IsInvisible)
        return;
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        SetVisibility(true);
        break;
    default:
        break;
    }
}

// X-Ray
void UFilterSkeletalMeshComponent::OnXrayPhoto_Implementation()
{
    if (IsInvisible)
        return;
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, XrayMaterial);
        break;
    case FilterVisibility::Hidden:
        if (IsVisible())
        {
            SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void UFilterSkeletalMeshComponent::OnXrayPhotoFinished_Implementation()
{
    if (IsInvisible)
        return;
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}

// Invisibility
void UFilterSkeletalMeshComponent::OnInvisPhoto_Implementation()
{
    if (IsInvisible)
    {
        SetMaterial(0, InvisMaterial);
        SetVisibility(true);
    }
}
void UFilterSkeletalMeshComponent::OnInvisPhotoFinished_Implementation()
{
    if (IsInvisible)
    {
        SetMaterial(0, DefaultMaterial);
        SetVisibility(false);
    }
}

void UFilterSkeletalMeshComponent::OnRevealFromInvisibility_Implementation()
{
    if (IsInvisible)
    {
        IsInvisible = false;
        SetMaterial(0, DefaultMaterial);
        SetVisibility(true);
        SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Ignore);
        SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

        bRenderCustomDepth = false;
        CustomDepthStencilValue = 0;
        MarkRenderStateDirty();
    }
}
void UFilterSkeletalMeshComponent::MakeInvisible()
{
    if (!IsInvisible)
    {
        IsInvisible = true;
        SetVisibility(false);
        SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
        SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);

        bRenderCustomDepth = true;
        CustomDepthStencilValue = 10;
        MarkRenderStateDirty();
    }
}