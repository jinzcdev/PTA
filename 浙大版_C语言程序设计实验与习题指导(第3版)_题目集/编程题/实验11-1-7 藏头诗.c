// https://pintia.cn/problem-sets/13/exam/problems/type/7?problemSetProblemId=587
#include <stdio.h>
#include <string.h>
int main() {
    char s[20];
    for (int i = 0; i < 4; i++) {
        scanf("%s", s);
        s[2] = '\0';
        printf("%s", s);
    }
    printf("\n");
    return 0;
}