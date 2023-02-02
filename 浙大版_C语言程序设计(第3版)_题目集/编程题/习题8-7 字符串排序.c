// https://pintia.cn/problem-sets/12/exam/problems/340
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
int main() {
    char s[5][80];
    for (int i = 0; i < 5; i++) scanf("%s", s[i]);
    qsort(s, 5, sizeof(s[0]), cmp);
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++) printf("%s\n", s[i]);
    return 0;
}