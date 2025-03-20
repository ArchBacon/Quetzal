// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#include "DiscoveryCraftingComponent.h"
#include "DiscoveryCraftingFunctionLibrary.h"
#include "DiscoveryCraftingSystem.h"
#include "RecipeData.h"
#include "Logging/StructuredLog.h"

UDiscoveryCraftingComponent::UDiscoveryCraftingComponent()
{
	
}

void UDiscoveryCraftingComponent::BeginPlay()
{
	Super::BeginPlay();

	// Immediately register all items and recipes
	UDiscoveryCraftingFunctionLibrary::FindAllCraftingItemsAndRecipes(Items, Recipes);
	// Recipes are already registered, but haven't been auto-discovered. We call the RegisterRecipes to auto discover
	// recipes from registered recipes
	RegisterRecipes(Recipes);
}

void UDiscoveryCraftingComponent::RegisterRecipes(const TArray<UDiscoveryRecipe*> InRecipes)
{
	Recipes = InRecipes;
	for (UDiscoveryRecipe* Recipe : InRecipes)
	{
		if (Recipe->AutoDiscover)
		{
			DiscoverRecipe_Internal(Recipe);
		}
	}
}

void UDiscoveryCraftingComponent::RegisterItems(const TArray<UDiscoveryItem*> InItems)
{
	Items = InItems;
}

void UDiscoveryCraftingComponent::RegisterItemsAndRecipes(
	const TArray<UDiscoveryItem*> InItems,
	const TArray<UDiscoveryRecipe*> InRecipes
) {
	RegisterItems(InItems);
	RegisterRecipes(InRecipes);
}

bool UDiscoveryCraftingComponent::DiscoverRecipe(UDiscoveryRecipe* Recipe)
{
	if (DiscoverRecipe_Internal(Recipe))
	{
		OnRecipeDiscovered.Broadcast(Recipe);
		return true;
	}

	return false;
}

bool UDiscoveryCraftingComponent::DiscoverRecipe_Internal(UDiscoveryRecipe* Recipe)
{
	if (!Recipe)
	{
		UE_LOGFMT(DiscoveryCraftingLog, Warning, "[{0}] Recipe is invalid.", GetOwner()->GetName());
		return false;
	}
	
	if (DiscoveredRecipes.Contains(Recipe))
	{
		UE_LOGFMT(DiscoveryCraftingLog, Log, "[{0}] Recipe \"{1}\" already discovered.", GetOwner()->GetName(), Recipe->Name.ToString());
		return false;
	}
	
	UE_LOGFMT(DiscoveryCraftingLog, Log, "[{0}] Recipe \"{1}\" discovered.", GetOwner()->GetName(), Recipe->Name.ToString());
	DiscoveredRecipes.Add(Recipe);
	
	return true;
}
