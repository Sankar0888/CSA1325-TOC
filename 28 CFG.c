#include <stdio.h>
#include <string.h>
int isBelongToCFG(const char* str, int index, int length) {
    if (index == length) {
        return 1; 
    }
    if (str[index] == '0' && isBelongToCFG(str, index + 1, length) && str[index + 1] == '1') {
        return isBelongToCFG(str, index + 2, length);
    }
    if (str[index] == '\0') {
        return 1; 
    }
    return 0;
}
int belongsToLanguage(const char* str) {
    int length = strlen(str);
    return isBelongToCFG(str, 0, length);
}
int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);
    if (belongsToLanguage(input)) {
        printf("Accepted: Input string belongs to the language defined by CFG\n");
    } else {
        printf("Rejected: Input string does not belong to the language defined by CFG\n");
    }

    return 0;
}
