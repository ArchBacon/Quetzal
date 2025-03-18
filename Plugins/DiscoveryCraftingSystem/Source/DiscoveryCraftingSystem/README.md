# Plugin Setup Guide

This guide will help you set up the plugin by configuring the Asset Manager to recognize crafting recipes and items.

## 1. Configure the Asset Manager

1. Open **Project Settings**.
2. Navigate to **Game > Asset Manager**.

### 2. Adding Recipes

1. Under **Primary Asset Types to Scan**, create a new entry.
2. Set **Primary Asset Type** to `DiscoveryRecipe`.
3. Set **Asset Base Class** to `DiscoveryRecipe`.
4. Under **Directories**, add a directory (e.g., `/Game` or a custom directory of your choice).

### 3. Adding Items

1. Under **Primary Asset Types to Scan**, create a new entry.
2. Set **Primary Asset Type** to `DiscoveryItem`.
3. Set **Asset Base Class** to `DiscoveryItem`.
4. Under **Directories**, add a directory (e.g., `/Game` or a custom directory of your choice).

## 4. API Reference

This section details the available functions, Blueprint nodes, and events provided by the plugin.

### Available Blueprint Nodes

- **Find All Crafting Recipes** - Retrieves all available crafting recipes.
- **Find All Crafting Items** - Retrieves all available crafting items.
- **Find All Crafting Recipes and Items** - Retrieves both recipes and items.

### Available Functions

*(Add C++ function signatures and descriptions here)*

### Available Events

*(Add any event dispatchers or delegates here)*

---

Your plugin is now ready to use! 🎮 Happy crafting!
