#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Encoding the message
void message_encoding(char message[50]) {
  printf("Enter the message : ");
  scanf("%s", message);

  for (int i = 0; message[i] != '\0'; i++)
  {

    // Check if all the characters in the string are in capital letters
    while (!isupper(message[i]) && message[i] != '\n' && message[i] != ' ') {
      printf("Enter the message : ");
      scanf("%s", message);
    }
  }
}

// Encoding the key
void key_encoding() { printf("Enter the key : "); }

void repeat(char key[50]) {
  scanf("%s", key);

  for (int i = 0; key[i] != '\0'; i++)
  {
    while (!isupper(key[i]) && key[i] != '\n' && key[i] != ' ') {
      printf("Enter the key : ");
      scanf("%s", key);
    }
  }

  printf("\nDuplicated key : ");
  for (int i = 0; i < 2; i++) {
    printf("%s", key);
  }
}

void encrypt(const char *message, const char *key, char *result) {
  const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  result[0] = '\0';

  for (int i = 0; i < strlen(message); i++)
  {
    if (message[i] == ' ') {
      strcat(result, " ");
    } else {
      int idx = strchr(alphabet, message[i]) - alphabet;
      int new_idx = (key[i % strlen(key)] - 'A' - idx + 26) % 26;
      strncat(result, &alphabet[new_idx], 1);
    }
  }
}

char message_frequencyLetter(char message[50]) {
  int freq[26] = {0};
  int maxFreqIndex = 0;

  for (int i = 0; i < strlen(message); i++)
  {

    // Ignore the characters are not letters
    if (isalpha(message[i])) {
      freq[message[i] - 'A']++;
    }
  }

  // Find the letters with the maximal frequency
  for (int i = 1; i < 26; i++)
  {
    if (freq[i] > freq[maxFreqIndex])
    {
      maxFreqIndex = i;
    }
  }

  char mostFrequent = 'A' + maxFreqIndex;

  return mostFrequent;
}

char key_frequencyLetter(char key[50]) {
  int freq[26] = {0};
  int maxFreqIndex = 0;

  for (int i = 0; i < strlen(key); i++)
  {

    // Ignore the characters are not letters
    if (isalpha(key[i]))
    {
      freq[key[i] - 'A']++;
    }
  }

  // Find the letters with the maximal frequency
  for (int i = 1; i < 26; i++)
  {
    if (freq[i] > freq[maxFreqIndex])
    {
      maxFreqIndex = i;
    }
  }

  char mostFrequent = 'A' + maxFreqIndex;

  return mostFrequent;
}

int main(void) {
  char message[50], key[50], ciphertext[50];

  message_encoding(message);
  key_encoding();
  repeat(key);

  encrypt(message, key, ciphertext);

  printf("\nCiphertext: %s", ciphertext);

  char freq1 = message_frequencyLetter(message);
  printf("\nMost frequency letter in the message : %c ", freq1);

  char freq2 = key_frequencyLetter(key);
  printf("\nMost frequency letter in the key : %c ", freq2);

  return 0;
}
