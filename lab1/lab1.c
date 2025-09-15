#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h> // for free()
#include <string.h>

int main() {
  char *readLine = NULL;
  size_t len = 0;
  size_t read;
  printf("Hello User! Please enter random text message:) : ");
  read = getline(&readLine, &len, stdin);
  // error handling
  if (read == -1) { // if terminal does not respond or user aborts
    perror("getline");
    free(readLine);
    return -1;
  }
  if (read == 1 &&
      readLine[0] ==
          '\n') { // if the user entered nothing it, intrrupt and ask again
    printf("please enter something: \n");
    read = getline(&readLine, &len, stdin);
  }

  // token part

  printf("Tokens:\n");

  char *tokenptr;
  char *token = strtok_r(readLine, " \n", &tokenptr);

  while (token != NULL) {
    printf(" %s\n", token);
    token = strtok_r(NULL, " \n", &tokenptr);
  }

  free(readLine);
  return 0;
}

/*
int main() {
  printf("Hello World!");
  return 0;
}
*/
