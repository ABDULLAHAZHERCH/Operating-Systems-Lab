#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

char* get_random_word() {
    const char* words[MAX_WORDS] = {
        "apple", "banana", "cherry", "orange", "grape",
        "strawberry", "pineapple", "watermelon", "kiwi", "mango"
    };

    int index = rand() % MAX_WORDS;
    return strdup(words[index]);
}

int main() {
    srand(time(0)); // Seed the random number generator
    char* secret_word = get_random_word();
    int word_length = strlen(secret_word);
    char* guessed_word = malloc(word_length + 1);
    memset(guessed_word, '_', word_length);
    guessed_word[word_length] = '\0';

    int attempts = 0;
    int correct_guesses = 0;
    char guess;

    printf("Welcome to Guess the Word!\n");
    printf("The secret word has %d letters.\n", word_length);

    while (correct_guesses < word_length) {
        printf("Secret word: %s\n", guessed_word);
        printf("Enter a letter guess: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < word_length; i++) {
            if (secret_word[i] == guess && guessed_word[i] != guess) {
                guessed_word[i] = guess;
                correct_guesses++;
                found = 1;
            }
        }

        if (!found) {
            attempts++;
            printf("Incorrect guess! Attempts: %d\n", attempts);
        }
    }

    printf("Congratulations! You guessed the word \"%s\" in %d attempts.\n", secret_word, attempts);

    free(secret_word);
    free(guessed_word);

    return 0;
}
