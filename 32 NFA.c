#include <stdio.h>
#include <stdbool.h>
#define MAX_STATES 10
void epsilonClosure(int nfa[MAX_STATES][MAX_STATES], int n, int state, bool visited[MAX_STATES]) {
    if (visited[state]) {
        return;
    }
    visited[state] = true;
    for (int i = 0; i < n; i++) {
        if (nfa[state][i] == 1) {
            epsilonClosure(nfa, n, i, visited);
        }
    }
}
void printEpsilonClosure(int nfa[MAX_STATES][MAX_STATES], int n) {
    printf("e-Closure for all states:\n");
    for (int i = 0; i < n; i++) {
        bool visited[MAX_STATES] = {false};
        printf("e-Closure(q%d): { ", i);
        epsilonClosure(nfa, n, i, visited);
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                printf("q%d ", j);
            }
        }
        printf("}\n");
    }
}
int main() {
    int n;
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &n);
    int nfa[MAX_STATES][MAX_STATES];
    printf("Enter the NFA transition table (1 for transition, 0 for no transition):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("q%d -> q%d: ", i, j);
            scanf("%d", &nfa[i][j]);
        }
    }
    printEpsilonClosure(nfa, n);
    return 0;
}
