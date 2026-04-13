#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100
#define MAX_NUM_COMMANDS 10

void display_help() {
    printf("Built-in commands:\n");
    printf("  exit - Exit the shell\n");
    printf("  help - Display this help message\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *commands[MAX_NUM_COMMANDS];
    
    while (1) {
        printf("MyOS Shell> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove the newline character
        input[strcspn(input, "\n")] = 0;

        // Parse commands
        commands[0] = strtok(input, " ");
        int i = 0;
        while (commands[i] != NULL) {
            i++;
            commands[i] = strtok(NULL, " ");
        }

        // Handle built-in commands
        if (strcmp(commands[0], "exit") == 0) {
            break;
        } else if (strcmp(commands[0], "help") == 0) {
            display_help();
        } else {
            printf("Command not recognized. Type 'help' for a list of commands.\n");
        }
    }
    return 0;
}