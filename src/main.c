#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  char [6000] user_input;

  printf("$ ");
  scanf("%[^\n]",&user_input);

  printf("%s: command not found\n",user_input);

  return 0;
}
