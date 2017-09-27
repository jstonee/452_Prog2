#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

void createServer(int, int, char*);

const int SIZE = 128;

int main ()
{
  char input[SIZE];
  char *token;
  
  while(1) {
    printf(">> ");
    fgets(input, SIZE, stdin);
    if (strcmp(input, "quit\n") == 0)
      exit(0);
    
    strcpy(&input[strlen(input)-1], "\000");
    token = strtok(input, " ");
    int i = 0;
    char *args[SIZE];
    memset(&args, '\000', sizeof(args));
    while (token != NULL) {
      args[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    if (strcmp(args[0], "createServer") == 0) {
      printf("%s %s %s %s\n", args[0], args[1], args[2], args[3]);
    }
    else if (strcmp(args[0], "abortServer") == 0) {
      printf("%s %s\n", args[0], args[1]);
    }
    else if (strcmp(args[0],"createProcess") == 0) {
      printf("%s %s\n", args[0], args[1]);
    }
    else if (strcmp(args[0], "abortProcess") == 0) {
      printf("%s %s\n", args[0], args[1]);
    }
    else if (strcmp(args[0],"displayStatus") == 0) {
      printf("%s\n", args[0]);
    }
    else {
      printf("Invalid command.\n");
    }
  }
  return 0;
}
