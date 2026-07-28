#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  char user_input [6000];

  while(true){

  	printf("$ ");

  	scanf("%[^\n]",&user_input);
	fflush(stdout);

  	printf("%s: command not found\n",user_input);
  }

  return 0;
}
