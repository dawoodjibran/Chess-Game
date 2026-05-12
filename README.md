# ♟️ Console Chess Engine (C++)

A fully functional, two-player Chess game built with **C++** using **Object-Oriented Programming (OOP)** principles. This project was developed as a core semester project to demonstrate the practical application of software engineering design patterns.

---

## 🚀 Features

* **Standard Chess Rules**: Implements unique movement logic for all pieces including Pawns, Rooks, Knights, Bishops, Queens, and Kings.
* **Path Validation**: Advanced logic for sliding pieces (Rook, Bishop, Queen) to ensure they cannot jump over obstacles.
* **Special Pawn Mechanics**: Supports the initial **two-step move** and diagonal enemy captures.
* **Capture System**: Automatically removes opponent pieces from the board and frees memory upon capture.
* **Win Condition**: Real-time detection of King capture to determine the winner and terminate the game.
* **Clean UI**: An interactive 8x8 coordinate-based grid rendered directly in the console.

---

## 🛠️ OOP Principles Demonstrated

This project serves as a comprehensive case study for the four pillars of OOP:

1.  **Inheritance**: A base `ChessPiece` class provides a blueprint, while specialized classes (e.g., `Pawn`, `Knight`) inherit and extend its functionality.
2.  **Polymorphism**: Uses a pure virtual function `isValidMove` in the base class, which is overridden by derived pieces to provide specific movement logic at runtime.
3.  **Encapsulation**: Private and protected members ensure data integrity, with access provided through controlled public methods.
4.  **Composition**: The `ChessBoard` class manages a 2D array of `ChessPiece` pointers, handling the lifecycle and interactions of all game objects.

---

## 📂 Project Structure

```text
.
├── ChessGame.h       # Header File containing all the class definitions
├── ChessGame.cpp     # Implementation of Header File
├── main.cpp          # Main File
├── README.md         # Project documentation and guide
└── .gitignore        # Standard C++ ignore file
```

---


## 🎮 How to Play

The game uses a standard **8x8 coordinate system (0-7)**.

1.  **Selection**: When prompted, enter the **Source** row and column of the piece you want to move.
2.  **Destination**: Enter the **Target** row and column where you want to move the piece.
3.  **Turn Management**: The game will automatically switch between White (Uppercase) and Black (Lowercase) turns.

**Example Input:**
To move a White Pawn from Row 6, Col 4 to Row 4, Col 4:
* Select Piece (Row Col): `6 4`
* Target Square (Row Col): `4 4`

---

## 👥 Contributors
* **Member 1** - *Muhammad Dawood* - [25F-3002]
* **Member 2** - *Abdullah Matloob* - [25F-3079]
* **Member 3** - *Faisal Ali* - [25F-3078]

---
