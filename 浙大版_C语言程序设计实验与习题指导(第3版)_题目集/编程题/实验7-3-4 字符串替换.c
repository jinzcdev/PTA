// https://pintia.cn/problem-sets/13/problems/525
#include <stdio.h>
#include <string.h>
int main() {
    char s[90];
    fgets(s, 90, stdin);
    int len = strlen(s) - 1;
    for (int i = 0; i < len; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = ('A' + 'Z') - s[i];
    printf("%s", s);
    return 0;
}