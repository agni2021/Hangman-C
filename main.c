#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For toupper() and isalpha()
#include <time.h>  // For time() to seed random number generator

#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 7 // Number of incorrect guesses allowed
#define NUM_WORDS 10

// Function to draw the hangman figure based on incorrect guesses
void drawHangman(int incorrectGuesses) {
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");
    printf("  %c   |\n", (incorrectGuesses >= 1) ? 'O' : ' ');
    printf(" %c%c%c  |\n", (incorrectGuesses >= 3) ? '/' : ' ',
                          (incorrectGuesses >= 2) ? '|' : ' ',
                          (incorrectGuesses >= 4) ? '\\' : ' ');
    printf(" %c %c  |\n", (incorrectGuesses >= 5) ? '/' : ' ',
                          (incorrectGuesses >= 6) ? '\\' : ' ');
    printf("      |\n");
    printf("=========\n");
}

int main() {
    // Array of words for the game
    const char *wordList[NUM_WORDS] = {
        "PROGRAMMING", "COMPUTER", "DEVELOPER", "ALGORITHM", "KEYBOARD",
        "MONITOR", "FUNCTION", "VARIABLE", "POINTER", "LIBRARY",
    };

    // Seed the random number generator
    srand(time(NULL));

    // Choose a random word from the list
    int randomIndex = rand() % NUM_WORDS;
    const char *secretWord = wordList[randomIndex];
    int wordLength = strlen(secretWord);

    // Initialize display word with underscores
    char displayWord[MAX_WORD_LENGTH + 1];
    for (int i = 0; i < wordLength; i++) {
        displayWord[i] = '_';
    }
    displayWord[wordLength] = '\0'; // Null-terminate the string

    // Keep track of guessed letters
    char guessedLetters[26] = {0}; // Initialize all to 0
    int numGuessedLetters = 0;

    int incorrectGuesses = 0;
    int gameWon = 0;

    printf("Welcome to Hangman!\n");
    printf("Guess the word by entering one letter at a time.\n");

    while (incorrectGuesses < MAX_GUESSES && !gameWon) {
        // Display game status
        drawHangman(incorrectGuesses);
        printf("\nWord: %s\n", displayWord);
        printf("Incorrect Guesses: %d/%d\n", incorrectGuesses, MAX_GUESSES);
        printf("Guessed Letters: ");
        for (int i = 0; i < numGuessedLetters; i++) {
            printf("%c ", guessedLetters[i]);
        }
        printf("\n");

        // Get user input
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess); // Notice the space before %c to consume newline

        // Convert guess to uppercase for case-insensitivity
        guess = toupper(guess);

        // Validate input
        if (!isalpha(guess)) {
            printf("Invalid input. Please enter a letter from A-Z.\n");
            continue;
        }

        // Check if letter has already been guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < numGuessedLetters; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You already guessed that letter. Try again.\n");
            continue;
        }

        // Add the current guess to the list of guessed letters
        guessedLetters[numGuessedLetters++] = guess;

        // Check if the guess is correct
        int foundLetter = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                displayWord[i] = guess;
                foundLetter = 1;
            }
        }

        if (foundLetter) {
            printf("Good guess!\n");
        } else {
            printf("Sorry, '%c' is not in the word.\n", guess);
            incorrectGuesses++;
        }

        // Check for win condition
        if (strcmp(displayWord, secretWord) == 0) {
            gameWon = 1;
        }
        printf("------------------------------------\n");
    }

    // Game End
    drawHangman(incorrectGuesses);
    if (gameWon) {
        printf("\nCongratulations! You guessed the word: %s\n", secretWord);
        printf("You Win!\n");
    } else {
        printf("\nGame Over! You ran out of guesses.\n");
        printf("The word was: %s\n", secretWord);
        printf("You Lose!\n");
    }

    return 0;
}