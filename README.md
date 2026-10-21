# Snake-and-ladders-game
This game was developed by me during my 3rd semester. I handwritten the C programming code myself and used Gemini to transform it into a fully functional game.


# 🐍 Snakes and Ladders — Doubly Linked List Edition

A complete implementation of the classic **Snakes and Ladders** board game powered by a **Doubly Linked List** data structure. 

This repository includes two versions of the game:
1. **C Console Application (`main.c`)**: The core data-structures implementation in C using `struct node` pointers (`next` and `prev`) to traverse the 100-tile board.
2. **Interactive Web Application (`index.html`)**: A modern, multiplayer HTML5/CSS3/JS graphical user interface that preserves the exact doubly linked list traversal logic, custom snake/ladder offsets, and game rules from the C program.

---

## 🧠 Data Structure & Core Architecture

Instead of using a standard 1D array or 2D matrix, the 100-square board is represented as a **Doubly Linked List** of 100 nodes (`1` to `100`):


struct node {
    int data;           // Tile number (1 to 100)
    struct node *next;  // Pointer to the next tile
    struct node *prev;  // Pointer to the previous tile
    int sl;             // Snake (< 0) or Ladder (> 0) offset
};