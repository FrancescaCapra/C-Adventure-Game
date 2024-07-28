# C-Adventure-Game

Welcome to the **C-Adventure-Game** repository! This project showcases advanced C programming techniques through a captivating character and inventory management game. 
## Game Overview

In this game, you take on the role of a master strategist responsible for managing a roster of characters, each with unique stats and abilities. Your task is to build and optimize your team by carefully selecting equipment and managing inventory. Use your skills to ensure your characters are ready for any challenge!

## Features

### Dynamic Character Management
- **Create and Customize**: Add new characters with specific attributes like health points (HP), magic points (MP), attack (ATK), defense (DEF), magic (MAG), and spirit (SPR).
- **Search and Modify**: Quickly find characters by their unique codes and update their equipment to boost their stats.

### Comprehensive Inventory System
- **Manage Equipment**: Keep track of a vast inventory of items, each with its own set of attributes. Equip your characters with the best gear to maximize their potential.
- **Read and Write**: Load your inventory from files and save your progress to ensure you never lose track of your items.

### Interactive Command-Line Interface
- **User-Friendly Menu**: Navigate through a simple yet powerful menu system to perform all game actions, from adding new characters to updating equipment.

## File Structure

- **pgList.h / pgList.c**: Handles the linked list of characters, including functions to initialize, free, read from file, print, insert, remove, and search characters.
- **pg.h / pg.c**: Defines the character structure and operations, including reading, printing, cleaning, updating equipment, and merging stats.
- **invArray.h / invArray.c**: Manages the inventory array, providing initialization, deallocation, reading, printing, searching, and stat retrieval functions.
- **equipArray.h / equipArray.c**: Manages character equipment, allowing initialization, deallocation, printing, updating, and associating equipment with characters.
- **inv.h / inv.c**: Handles inventory item operations, including reading, printing, and stat management.
- **main.c**: The main program loop, providing a menu-driven interface for interacting with the character and inventory systems.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Standard C library

### Compilation

To compile and run the project, use the following command:
```sh
gcc -o game main.c pgList.c pg.c invArray.c equipArray.c inv.c
./game


