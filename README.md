# Hangman Game in C

A classic CLI-based Hangman game implemented in C. Test your vocabulary skills by guessing letters to uncover the hidden word before the hangman is fully drawn!

## Features

- Classic Hangman gameplay in the terminal
- Random word selection from a programming-themed word list
- Visual hangman that updates with each incorrect guess
- Input validation to ensure only letters are accepted
- Prevention of duplicate letter guesses
- Win/loss detection with appropriate messages
- Case-insensitive input handling

## How to Play

1. The game randomly selects a word from a predefined list of programming-related terms
2. You need to guess the word by entering one letter at a time
3. For each correct guess, the letter will appear in its correct position(s) in the word
4. For each incorrect guess, a part of the hangman figure will be drawn
5. You have 7 incorrect guesses before the game ends
6. If you guess all letters correctly before using all guesses, you win!
7. If the hangman figure is fully drawn, you lose

## Game Controls

- Enter a single letter (A-Z or a-z) when prompted
- The game will validate your input and provide feedback
- Previous guesses are tracked and displayed
- The game prevents duplicate guesses

## Word List

The game randomly selects from these programming-related words:
- PROGRAMMING
- COMPUTER
- DEVELOPER
- ALGORITHM
- KEYBOARD
- MONITOR
- FUNCTION
- VARIABLE
- POINTER
- LIBRARY

## Requirements

- A C compiler (GCC, Clang, etc.)
- A terminal or command prompt

## How to Compile and Run

### On Linux/Mac:
```bash
gcc main.c -o hangman
./hangman
```

### On Windows:
```cmd
gcc main.c -o hangman.exe
hangman.exe
```

### Using provided executable:
If you're on Windows, you can directly run the provided executable:
```cmd
main.exe
```

## Game Interface

```
Welcome to Hangman!
Guess the word by entering one letter at a time.

  +---+
  |   |
      |
      |
      |
      |
=========
Word: _______
Incorrect Guesses: 0/7
Guessed Letters: 

Enter a letter: 
```

## Technical Details

- Language: C
- Uses standard libraries: stdio.h, stdlib.h, string.h, ctype.h, time.h
- Implements a visual hangman using ASCII art
- Random word selection using srand() and rand()
- Case-insensitive input handling with toupper()
- Input validation to ensure only alphabetic characters are accepted
- Memory-efficient implementation with fixed-size arrays

## Game Rules

1. You start with 7 incorrect guesses
2. Each incorrect guess adds a part to the hangman figure:
   - 1st wrong guess: Head
   - 2nd wrong guess: Body
   - 3rd wrong guess: Left arm
   - 4th wrong guess: Right arm
   - 5th wrong guess: Left leg
   - 6th wrong guess: Right leg
3. Guessing a correct letter reveals all instances of that letter in the word
4. Duplicate guesses are not counted as incorrect
5. Invalid input (non-alphabetic characters) is rejected

## Screenshots

### Game in Progress
```
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
Word: P_O_R_M___
Incorrect Guesses: 3/7
Guessed Letters: P R O M A L T
```

### Win State
```
  +---+
  |   |
      |
      |
      |
      |
=========
Congratulations! You guessed the word: PROGRAM
You Win!
```

### Loss State
```
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
Game Over! You ran out of guesses.
The word was: PROGRAMMING
You Lose!
```

## Author

This Hangman game was developed as a simple C programming exercise.

## License

This project is open source and available under the MIT License.
