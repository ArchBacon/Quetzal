// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiscoveryCraftingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRecipeDiscovered, UDiscoveryRecipe*, Recipe);

class UDiscoveryItem;
class UDiscoveryRecipe;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DISCOVERYCRAFTINGSYSTEM_API UDiscoveryCraftingComponent : public UActorComponent
{
	GENERATED_BODY()

	/**
	 * All items and recipes, should be validated on component initialization in editor and debug.
	 * These should also be moved to a manager so multiple components do not populate memory with the same data
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=CraftingSystem, meta=(AllowPrivateAccess="true"))
	TArray<UDiscoveryItem*> Items;					// All registered items in the game

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=CraftingSystem, meta=(AllowPrivateAccess="true"))
	TArray<UDiscoveryRecipe*> Recipes;				// All registered recipes in the game

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CraftingSystem, meta=(AllowPrivateAccess="true"))
	TArray<UDiscoveryRecipe*> DiscoveredRecipes;	// All player discovered recipes
	
public:
	UDiscoveryCraftingComponent();

	UPROPERTY(BlueprintAssignable)
	FOnRecipeDiscovered OnRecipeDiscovered;
	
public:
	UFUNCTION(BlueprintCallable)
	void RegisterRecipes(TArray<UDiscoveryRecipe*> InRecipes);

	UFUNCTION(BlueprintCallable)
	void RegisterItems(TArray<UDiscoveryItem*> InItems);

	UFUNCTION(BlueprintCallable)
	void RegisterItemsAndRecipes(TArray<UDiscoveryItem*> InItems, TArray<UDiscoveryRecipe*> InRecipes);

	UFUNCTION(BlueprintCallable)
	void DiscoverRecipe(UDiscoveryRecipe* Recipe);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UDiscoveryRecipe*> GetDiscoveredRecipes() const { return DiscoveredRecipes; };
};
