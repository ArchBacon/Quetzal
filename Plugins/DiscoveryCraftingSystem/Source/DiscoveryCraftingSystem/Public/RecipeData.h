// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RecipeData.generated.h"

class UDiscoveryItem;

USTRUCT(BlueprintType)
struct FIngredients
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Ingredient, DisplayName="Ingredients & Amounts")
	TMap<UDiscoveryItem*, int> Ingredients = {};
};

// Describes a recipe's input and output
UCLASS(BlueprintType)
class DISCOVERYCRAFTINGSYSTEM_API UDiscoveryRecipe : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Config)
	bool AutoDiscover = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Recipe)
	FIngredients Input = {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Recipe)
	FIngredients Output = {};
};

// Describes an item's Name, Description, and Icon
UCLASS(BlueprintType)
class DISCOVERYCRAFTINGSYSTEM_API UDiscoveryItem : public UPrimaryDataAsset
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
