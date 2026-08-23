#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  char buffer [6000];
  char command [6000];
  char exit_command[] = "exit";

  while(true){

  	printf("$ ");

  	fgets(buffer, sizeof(buffer), stdin);     // Scans the command
    sscanf(buffer, "%6000s", command );       // fget() + sscanf() instead of scanf()

    if(strncmp(command, exit_command, strlen(exit_command))==0){  // Break the loop if command is "exit"
      break;
    }

  	printf("%s: command not found\n", command);   // TEMPORY: output command
    fflush(stdout);  //    flush buffered output
  }

  return 0;
}
