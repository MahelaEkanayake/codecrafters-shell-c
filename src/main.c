#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  char buffer [6000];
  char command [6000];

  while(true){

  	printf("$ ");

  	fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%6000s", command );

  	printf("%s: command not found\n", command);
    fflush(stdout);
  }

  return 0;
}
