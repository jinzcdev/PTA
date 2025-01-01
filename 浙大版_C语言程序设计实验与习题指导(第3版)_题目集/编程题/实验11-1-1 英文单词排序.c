// https://pintia.cn/problem-sets/13/exam/problems/type/7?problemSetProblemId=586
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char s[10];
    int order, length;
} word[20];
int cmp(const void *a, const void *b) {
    struct node *sa = (struct node *)a;
    struct node *sb = (struct node *)b;
    return sa->length != sb->length ? sa->length - sb->length
                                    : sa->order - sb->order;
}
int main() {
    int len = 0;
    while (scanf("%s", word[len].s), word[len].s[0] != '#') {
        word[len].order = len;
        word[len].length = strlen(word[len].s);
        len++;
    }
    qsort(word, len, sizeof(struct node), cmp);
    for (int i = 0; i < len; i++) printf("%s ", word[i].s);
    return 0;
}