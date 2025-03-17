// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#include "DiscoveryCraftingComponent.h"

UDiscoveryCraftingComponent::UDiscoveryCraftingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UDiscoveryCraftingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UDiscoveryCraftingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

