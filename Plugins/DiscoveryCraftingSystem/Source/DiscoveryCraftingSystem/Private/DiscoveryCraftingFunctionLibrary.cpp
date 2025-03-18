// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "DiscoveryCraftingFunctionLibrary.h"
#include "Engine/AssetManager.h"

void UCyberneticFunctionLibrary::FindAllCraftingRecipes(TArray<UDiscoveryRecipe*>& Recipes)
{
	const UAssetManager& AssetManager = UAssetManager::Get();
	TArray<FAssetData> Assets{};
	Recipes.Empty();

	AssetManager.GetPrimaryAssetDataList(FPrimaryAssetType(FName("DiscoveryRecipe")), Assets);
	for (const FAssetData& Asset : Assets)
	{
		Recipes.Add(Cast<UDiscoveryRecipe>(Asset.GetAsset()));
	}
}

void UCyberneticFunctionLibrary::FindAllCraftingItems(TArray<UDiscoveryItem*>& Items)
{
	const UAssetManager& AssetManager = UAssetManager::Get();
	TArray<FAssetData> Assets{};
	Items.Empty();

	AssetManager.GetPrimaryAssetDataList(FPrimaryAssetType(FName("DiscoveryItem")), Assets);
	for (const FAssetData& Asset : Assets)
	{
		Items.Add(Cast<UDiscoveryItem>(Asset.GetAsset()));
	}
}

void UCyberneticFunctionLibrary::FindAllCraftingItemsAndRecipes(
	TArray<UDiscoveryItem*>& Items,
	TArray<UDiscoveryRecipe*>& Recipes
) {
	FindAllCraftingRecipes(Recipes);
	FindAllCraftingItems(Items);
}
