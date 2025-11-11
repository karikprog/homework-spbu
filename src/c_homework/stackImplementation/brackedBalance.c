#include <stdio.h>
#include <string.h>

#include "stack.h"

int brackedBalance(char str[])
{
    DynamicStack* s = createStack();
    int l = strlen(str);
    int i;
    int fl = 1;
    for (i = 0; i < l; ++i) {
        if ((str[i] == '{') || (str[i] == '[') || str[i] == '(') {
            push(s, str[i]);
        }
        if (str[i] == '}') {
            if (peak(s) != '{') {
                fl = 0;
                break;
            }
            pop(s);
        }
        if (str[i] == ']') {
            if (peak(s) != '[') {
                fl = 0;
                break;
            }
            pop(s);
        }
        if (str[i] == ')') {
            if (peak(s) != '(') {
                fl = 0;
                break;
            }
            pop(s);
        }
    }
    destroyStack(s);
    if (fl) {
        return 1;
    }
    return 0;
}

int main(void)
{
    printf("%d\n", brackedBalance("sdk{{akjfh(ajf[[afjkjd[(akjdfk)]]])}}"));

    return 0;
}