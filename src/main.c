#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define INPUT_CHARACTER_LENGTH 8192

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage

  char buffer [INPUT_CHARACTER_LENGTH];
  char command [INPUT_CHARACTER_LENGTH];
  const char *shell_builtin[] = {"exit", "echo", "type"};

  while(true){

  	printf("$ ");

  	fgets(buffer, sizeof(buffer), stdin);     // Scans the command
    sscanf(buffer, "%[^\n]", command);       // fget() + sscanf() instead of scanf()

    if(strncmp(command, shell_builtin[0], strlen(shell_builtin[0]))==0){  // Break the loop if command is "exit"
      break;
    }else if(strncmp(command, shell_builtin[1], strlen(shell_builtin[1]))==0){ // echo a string
      
      char *arg = command + strlen(shell_builtin[1]);   // skip the "echo" keyword
      while (*arg && isspace((unsigned char)*arg))  // skip the spaces
        arg++;
      printf("%s\n", arg);

    }else if(strncmp(command, shell_builtin[2], strlen(shell_builtin[2]))==0){ // type command
      
      char *arg = command + strlen(shell_builtin[2]); 
      while (*arg && isspace((unsigned char)*arg))
        arg++;

      char *token = strtok(arg, " ");  // strtok() for splitting the string into tokens
      bool is_token_a_shell_builtin = false;

      size_t builtin_count = sizeof(shell_builtin) / sizeof(shell_builtin[0]);

      while(token != NULL){
        
        for(size_t i = 0; i < builtin_count; i++){ 
          if(strncmp(token, shell_builtin[i], strlen(shell_builtin[i]))==0){  // check whether the token is a shell builtin
            printf("%s is a shell builtin\n",token);
            fflush(stdout);
            is_token_a_shell_builtin = true;
            break;
          }
        }

        if(is_token_a_shell_builtin == false){
          printf("%s: not found\n", token);
          fflush(stdout);
        }

        token = strtok(NULL, " ");
      }

    }else{
      printf("%s: command not found\n", command);   // error command
    }

    fflush(stdout);  //    flush buffered output
  }

  return 0;
}
