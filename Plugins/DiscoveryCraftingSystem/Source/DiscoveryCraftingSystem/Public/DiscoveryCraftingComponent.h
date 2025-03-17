// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "DiscoveryCraftingComponent.generated.h"

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
	TMap<FGameplayTag, UDiscoveryItem*> Items;		// All registered items in the game
	TMap<FGameplayTag, UDiscoveryRecipe*> Recipes;	// All registered recipes in the game

	/**
	 * Owned items could be moved to a child component since it is not mandatory and is basically and inventory system.
	 * Creating a child of this component that contains this is much cleaner and leaner. This also allows user to implement
	 * their own versions of inventory systems without any bloat.
	 */
	TMap<FGameplayTag, int> OwnedItems;				// List of owned items and amounts
	TArray<FGameplayTag> DiscoveredRecipes;			// All player discovered recipes
	
public:
	UDiscoveryCraftingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
