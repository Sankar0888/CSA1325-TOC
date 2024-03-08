#include <stdio.h>
int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == 'b') return 1; 
            else return -1; 
        case 1:
            if (input == 'b' || input == 'a') return 1;
            else return -1; 
        case 2:
            if (input == 'a') return 3; 
            else return -1; 
        case 3:
            return -1; 
        default:
            return -1; 
    }
}
int simulateNFA(const char* input) {
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
    if (currentState == 3) {
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
    simulateNFA(input);
    return 0;
}
