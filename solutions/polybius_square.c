#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get user input message (only uppercase letters allowed)
void message_encoding(char message[50]) {
  printf("Enter the message: ");
  scanf("%s", message);

  // Ensure the input is in uppercase
  for (int i = 0; message[i] != '\0'; i++) {
    while (!isupper(message[i])) {
      printf("Invalid input! Enter the message in uppercase: ");
      scanf("%s", message);
    }
  }
}

// Function to generate a random Polybius square
void polybius_square(char array[5][5]) {
  char used[26] = {0};                             // Tracks used characters
  srand(time(NULL));                               // Seed random function
  char characters[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // 'J' is merged with 'I'

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      char randomChar;
      bool unique;

      // Generate unique random character for the square
      do {
        unique = true;
        int randomIndex = rand() % 25;
        randomChar = characters[randomIndex];

        if (used[randomChar - 'A']) {
          unique = false;
        }
      } while (!unique);

      array[i][j] = randomChar;
      used[randomChar - 'A'] = 1;
    }
  }
}

// Function to display the Polybius square
void display(char array[5][5]) {
  printf("\nPolybius Square:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%3c", array[i][j]);
    }
    printf("\n");
  }
}

// Function to encrypt the message using the Polybius square
void polybius_cipher(char array[5][5], const char *message,
                     int ciphertext[50][2]) {
  int size = strlen(message);
  printf("\nCipherText: ");

  for (int i = 0; i < size; i++) {
    int found = 0;
    for (int j = 0; j < 5 && !found; j++) {
      for (int k = 0; k < 5 && !found; k++) {
        if (array[j][k] == message[i]) {
          ciphertext[i][0] = j;
          ciphertext[i][1] = k;
          printf("%d%d", ciphertext[i][0],
                 ciphertext[i][1]); // Print cipher pair
          found = 1;
        }
      }
    }
    if (!found) {
      printf("Character %c not found in Polybius square.\n", message[i]);
    }
  }
  printf("\n");
}

// Function to decrypt the ciphertext using the Polybius square
void polybius_decipher(char array[5][5], int ciphertext[50][2], int size) {
  printf("Decrypted Message: ");
  for (int i = 0; i < size; i++) {
    int row = ciphertext[i][0];
    int col = ciphertext[i][1];
    printf("%c", array[row][col]);
  }
  printf("\n");
}

int main(void) {
  char message[50], array[5][5];
  int ciphertext[50][2];

  message_encoding(message);
  polybius_square(array);
  display(array);

  polybius_cipher(array, message, ciphertext);
  polybius_decipher(array, ciphertext, strlen(message));

  return 0;
}
