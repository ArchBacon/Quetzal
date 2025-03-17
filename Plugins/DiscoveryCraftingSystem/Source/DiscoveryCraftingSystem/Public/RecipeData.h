// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "RecipeData.generated.h"

USTRUCT(BlueprintType)
struct FIngredients
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Ingredient, meta=(ForceInlineRow))
	TMap<FGameplayTag, int> Ingredients = {};
};

// Describes a recipe's input and output
UCLASS(BlueprintType)
class DISCOVERYCRAFTINGSYSTEM_API UDiscoveryRecipe : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FGameplayTag RecipeTag = {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Recipe)
	FIngredients Ingredients = {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Recipe)
	FIngredients Result = {};
};

// Base class for items. Describes an item's owning gameplay tag
UCLASS(BlueprintType)
class DISCOVERYCRAFTINGSYSTEM_API UDiscoveryItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FGameplayTag ItemTag = {};
};

// Describes an item's Name, Description, and Icon
UCLASS(BlueprintType)
class DISCOVERYCRAFTINGSYSTEM_API UDiscoveryDetailedItem : public UDiscoveryItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Display)
	FText Name = {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Display, meta=(MultiLine="true"))
	FText Description = {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Display)
	TObjectPtr<UTexture2D> Thumbnail = nullptr;
};
