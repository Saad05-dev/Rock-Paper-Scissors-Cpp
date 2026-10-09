# Rock Paper Scissors (C++)

A console Rock Paper Scissors game written in C++, built as an exercise for a C++ programming course.

You choose how many rounds to play, then pick Rock, Paper or Scissors each round against a computer opponent that chooses randomly. After the last round, the game shows the total wins, losses and draws, announces the overall winner, and lets you play again.

## Features

- Choose the number of rounds
- Input validation for invalid choices
- Round-by-round results
- Final scoreboard with the overall winner
- Replay option

## Requirements

- A C++ compiler such as `g++`

## Compile and run

**Linux / macOS**

```bash
g++ main.cpp -o main
./main
```

**Windows (MinGW)**

```bash
g++ main.cpp -o main.exe
main.exe
```

## How to play

1. Enter the number of rounds.
2. Each round, enter `1` for Rock, `2` for Paper or `3` for Scissor.
3. Read the round result, then repeat until all rounds are done.
4. Check the final scoreboard and choose whether to play again.

## Also available as a web app

The same game is available in HTML, CSS and JavaScript: 
[https://github.com/Saad05-dev/Rock-Paper-Scissors-Web]