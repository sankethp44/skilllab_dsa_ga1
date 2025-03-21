#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

bool isMatchingPair(char a, char b) {
    return (a == '(' && b == ')') || 
           (a == '{' && b == '}') || 
           (a == '[' && b == ']');
}

bool areBracketsBalanced(char exp[]) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            if (top == MAX - 1) return false;  // Stack overflow
            stack[++top] = exp[i];  // Push
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatchingPair(stack[top--], exp[i])) 
                return false;
        }
    }
    return top == -1;
}

int main() {
    char exp[] = "{()}[]";
    printf(areBracketsBalanced(exp) ? "Balanced\n" : "Not Balanced\n");
    return 0;
}
