#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  

  while(true){
	
	char user_input [6000];

  	printf("$ ");
  	scanf("%[^\n]",&user_input);

  	printf("%s: command not found\n",user_input);
  }

  return 0;
}
