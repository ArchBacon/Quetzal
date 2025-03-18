// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "RecipeData.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DiscoveryCraftingFunctionLibrary.generated.h"

UCLASS()
class DISCOVERYCRAFTINGSYSTEM_API UCyberneticFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static void FindAllCraftingRecipes(TArray<UDiscoveryRecipe*>& Recipes);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static void FindAllCraftingItems(TArray<UDiscoveryItem*>& Items);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static void FindAllCraftingItemsAndRecipes(TArray<UDiscoveryItem*>& Items, TArray<UDiscoveryRecipe*>& Recipes);
};
