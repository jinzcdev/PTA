// https://pintia.cn/problem-sets/13/exam/problems/529
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *((char *)a) - *((char *)b); }
int main() {
    char ch, s[80];
    int len = 0, hash[128] = {0};
    while (ch = getchar(), ch != '\n') {
        if (!hash[ch]) {
            hash[ch] = 1;
            s[len++] = ch;
        }
    }
    s[len] = '\0';
    qsort(s, len, sizeof(char), cmp);
    printf("%s", s);
    return 0;
}