#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  char buffer [6000];
  char command [6000];
  char exit_command[] = "exit";
  char echo_command[] = "echo";

  while(true){

  	printf("$ ");

  	fgets(buffer, sizeof(buffer), stdin);     // Scans the command
    sscanf(buffer, "%6000s", command );       // fget() + sscanf() instead of scanf()

    if(strncmp(command, exit_command, strlen(exit_command))==0){  // Break the loop if command is "exit"
      break;
    }else if(strncmp(command, echo_command, strlen(echo_command))==0){ // echo a string
      
      char *arg = command + strlen(echo_command);   // skip the "echo" keyword
      while (*arg && issapce((unsigned char)*arg))  // skip the spaces
        arg++;
      printf("%s\n", arg);

    }else{
      printf("%s: command not found\n", command);   // error command
    }

    fflush(stdout);  //    flush buffered output
  }

  return 0;
}
