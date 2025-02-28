#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to encode the message input by the user
void message_encoding(char message[50]) {
  printf("Enter the message: ");
  scanf("%s", message);

  // Validate that all characters in the message are uppercase letters
  for (int i = 0; message[i] != '\0'; i++) {
    while (!isupper(message[i]) && message[i] != '\n' && message[i] != ' ') {
      printf("Enter the message: ");
      scanf("%s", message);
    }
  }
}

// Function to prompt the user to enter the key (not fully implemented)
void key_encoding() { printf("Enter the key: "); }

// Function to repeat the key input by the user twice
void repeat(char key[50]) {
  scanf("%s", key);

  // Validate that all characters in the key are uppercase letters
  for (int i = 0; key[i] != '\0'; i++) {
    while (!isupper(key[i]) && key[i] != '\n' && key[i] != ' ') {
      printf("Enter the key: ");
      scanf("%s", key);
    }
  }

  // Print the duplicated key
  printf("\nDuplicated key: ");
  for (int i = 0; i < 2; i++) {
    printf("%s", key);
  }
}

// Function to encrypt the message using the Beaufort cipher
void encrypt(const char *message, const char *key, char *result) {
  const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  result[0] = '\0'; // Initialize result as an empty string

  // Perform the encryption process
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == ' ') {
      strcat(result, " "); // Preserve spaces in the message
    } else {
      int idx =
          strchr(alphabet, message[i]) -
          alphabet; // Find the index of the message character in the alphabet
      int new_idx = (key[i % strlen(key)] - 'A' - idx + 26) %
                    26; // Calculate the new index using Beaufort cipher formula
      strncat(result, &alphabet[new_idx],
              1); // Append the new character to the result
    }
  }
}

// Function to find the most frequent letter in the message
char message_frequencyLetter(char message[50]) {
  int freq[26] = {0};
  int maxFreqIndex = 0;

  // Count the frequency of each letter in the message
  for (int i = 0; i < strlen(message); i++) {
    if (isalpha(message[i])) {
      freq[message[i] - 'A']++;
    }
  }

  // Find the letter with the highest frequency
  for (int i = 1; i < 26; i++) {
    if (freq[i] > freq[maxFreqIndex]) {
      maxFreqIndex = i;
    }
  }

  char mostFrequent = 'A' + maxFreqIndex;
  return mostFrequent;
}

// Function to find the most frequent letter in the key
char key_frequencyLetter(char key[50]) {
  int freq[26] = {0};
  int maxFreqIndex = 0;

  // Count the frequency of each letter in the key
  for (int i = 0; i < strlen(key); i++) {
    if (isalpha(key[i])) {
      freq[key[i] - 'A']++;
    }
  }

  // Find the letter with the highest frequency
  for (int i = 1; i < 26; i++) {
    if (freq[i] > freq[maxFreqIndex]) {
      maxFreqIndex = i;
    }
  }

  char mostFrequent = 'A' + maxFreqIndex;
  return mostFrequent;
}

// Function to save the message, key, ciphertext, and frequency letters to a
// file
void backup_file(const char *message, const char *key, const char *result,
                 char freq_m, char freq_k) {
  FILE *file = fopen("beaufort_cipher.txt", "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  // Write the encoded message, key, ciphertext, and frequency letters to the
  // file
  fprintf(file, "Message encoded: %s\n", message);
  fprintf(file, "Key encoded: %s\n", key);
  fprintf(file, "Ciphertext: %s\n", result);
  fprintf(file, "Most frequent letter in the message: %c\n", freq_m);
  fprintf(file, "Most frequent letter in the key: %c\n", freq_k);

  fclose(file);
}

int main(void) {
  char message[50], key[50], ciphertext[50];

  // Encode the message
  message_encoding(message);
  // Prompt the user to enter the key
  key_encoding();
  // Repeat the key twice
  repeat(key);

  // Encrypt the message using the key
  encrypt(message, key, ciphertext);

  // Print the resulting ciphertext
  printf("\nCiphertext: %s", ciphertext);

  // Find and print the most frequent letter in the message
  char freq1 = message_frequencyLetter(message);
  printf("\nMost frequent letter in the message: %c ", freq1);

  // Find and print the most frequent letter in the key
  char freq2 = key_frequencyLetter(key);
  printf("\nMost frequent letter in the key: %c ", freq2);

  // Save the message, key, ciphertext, and frequency letters to a file
  backup_file(message, key, ciphertext, freq1, freq2);

  return 0;
}
