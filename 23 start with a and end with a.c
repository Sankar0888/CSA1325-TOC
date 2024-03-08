#include <stdio.h>
int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == 'a') return 1; 
            else return -1; 
        case 1:
            if (input == 'b') return 1; 
            else return -1; 
        default:
            return -1; 
    }
}
int simulateDFA(const char* input) {
    int currentState = 0;
    int i = 0;
    while (input[i] != '\0') {
        currentState = transition(currentState, input[i]);
        if (currentState == -1) {
            printf("Invalid input: %c at position %d\n", input[i], i + 1);
            return 0; 
        }
        i++;
    }
    if (currentState == 1) {
        printf("Accepted: Input string is in the language\n");
        return 1; 
    } else {
        printf("Rejected: Input string is not in the language\n");
        return 0; 
    }
}
int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);
    simulateDFA(input);
    return 0;
}
