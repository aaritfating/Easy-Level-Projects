# Easy Level Projects

This repository contains my early beginner-friendly C++ projects as I start my programming journey.

---

## 📘 Project 1: Quiz Game in C++

A simple console-based multiple-choice quiz game written in C++.  
The game asks the user a series of questions, takes input, checks the answer, and keeps track of the score.

---

### 🎯 Features

- Multiple-choice questions (a, b, c, d)
- Case-insensitive answers (`A` and `a` are treated the same)
- Score tracking
- Simple and beginner-friendly C++ code structure
- Separated logic using functions:
  - `greet()` – welcomes the player
  - `instructions()` – shows how to play
  - `questions()` – asks all questions
  - `askquestions()` – handles each question and answer check

---

### 🧠 Concepts Used

- `iostream` and `string`
- Functions in C++
- Passing arguments by `const reference`
- Basic input/output (`cin`, `cout`)
- Conditional statements (`if-else`)
- Character handling with `<cctype>` (`tolower`)

---

### 🖥️ How to Run

1. Make sure you have a C++ compiler installed (e.g., `g++`).
2. Compile the program:

   ```bash
   g++ main.cpp -o quiz_game
