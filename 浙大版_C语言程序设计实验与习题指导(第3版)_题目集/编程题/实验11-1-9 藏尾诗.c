// https://pintia.cn/problem-sets/13/exam/problems/588
#include <stdio.h>
#include <string.h>
int main() {
    char s[20];
    for (int i = 0; i < 4; i++) {
        scanf("%s", s);
        int len = strlen(s);
        printf("%s", s + len - 2);
    }
    printf("\n");
    return 0;
}