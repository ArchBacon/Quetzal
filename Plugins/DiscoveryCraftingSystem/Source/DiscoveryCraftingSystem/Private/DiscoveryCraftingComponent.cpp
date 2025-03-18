// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#include "DiscoveryCraftingComponent.h"
#include "RecipeData.h"

UDiscoveryCraftingComponent::UDiscoveryCraftingComponent()
{
	
}

void UDiscoveryCraftingComponent::RegisterRecipes(const TArray<UDiscoveryRecipe*> InRecipes)
{
	Recipes = InRecipes;
	for (UDiscoveryRecipe* Recipe : InRecipes)
	{
		if (Recipe->AutoDiscover)
		{
			DiscoverRecipe(Recipe);
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

void UDiscoveryCraftingComponent::DiscoverRecipe(UDiscoveryRecipe* Recipe)
{
	DiscoveredRecipes.Add(Recipe);
	OnRecipeDiscovered.Broadcast(Recipe);
}

