# Math Game

This project is a simple console-based math quiz game built for practice with programming fundamentals, clean code, and divide-and-conquer design.

> Note: This code currently uses Windows-specific console commands in `GetScreenColor` and `ResetScreen`, so it is intended to run on Windows only. To make it work on another operating system, change the `system("command")` string in those functions to the equivalent command for your OS command line.

## About

The game lets a player answer a configurable number of arithmetic questions with a choice of difficulty and operation types. It demonstrates basic C++ programming skills while keeping the code organized and readable.

## Features

- Choose the number of questions to play (1 to 100).
- Choose a quiz difficulty level: Easy, Medium, Hard, or Mixed.
- Choose an operation type: Addition, Subtraction, Multiplication, Division, or Mixed.
- Randomly generated arithmetic questions.
- Immediate feedback for correct and incorrect answers.
- Final quiz summary with correct and incorrect answer counts.
- Replay prompt after each game.
- Simple console UI with screen reset and color feedback based on the result.
- Clean code structure using enums, structs, and helper functions.

## How to play

1. Run the program.
2. Enter the number of questions to answer.
3. Choose the quiz difficulty level.
4. Choose the operation type.
5. For each question, enter your answer.
6. The program will show whether your answer is correct or incorrect.
7. After all questions, the final results are displayed.
8. Choose whether to play again.

## How to run

### Using Visual Studio

1. Open `Math Game.sln` in Visual Studio.
2. Build the solution.
3. Run the project.

## Programming topics covered

- C++ input/output (`cin`, `cout`)
- Control flow (`if`, `switch`, loops)
- Enumerations (`enum`)
- Structs for grouping related data
- Functions for modular code
- Random number generation
- Basic game loop logic
- Screen reset and simple console UI feedback

## Code organization

The project uses separate helper functions and data structures to keep logic clean. The code is divided into small units for reading input, generating questions, checking answers, and printing results.
