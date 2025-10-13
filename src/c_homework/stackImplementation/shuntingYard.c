#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

int bracketCount(char str[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == ')') {
            c++;
        }
    }
    return c;
}
int getOperatorPriority(char v)
{
    if (v == '*' || v == '/') {
        return 2;
    } else if (v == '+' || v == '-') {
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char v)
{
    return v == '*' || v == '/' || v == '+' || v == '-';
}

void shuntingYard(char str[], char resultStr[], int n)
{
    DynamicStack* s = createStack();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (isdigit(str[i])) {
            resultStr[j] = str[i];
            j++;
        } else if (isOperator(str[i])) {
            while (!isEmpty(s) && isOperator(peak(s)) && (getOperatorPriority(peak(s)) >= getOperatorPriority(str[i]))) {
                resultStr[j] = pop(s);
                j++;
            }
            push(s, str[i]);
        } else if (str[i] == '(') {
            push(s, str[i]);
        } else if (str[i] == ')') {
            while (peak(s) != '(') {
                resultStr[j] = pop(s);
                j++;
            }
            pop(s);
        }
    }
    while (!isEmpty(s)) {
        resultStr[j] = pop(s);
        j++;
    }
    destroyStack(s);
}

int main(void)
{
    char s1[] = "((1+2)*(3+4))";
    int n = strlen(s1);
    int lenS2 = n - bracketCount(s1, n);
    char s2[lenS2];
    shuntingYard(s1, s2, n);
    for (int i = 0; i < lenS2; i++) {
        printf("%c ", s2[i]);
    }
    printf("\n");
    return 0;
}