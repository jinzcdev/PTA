// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=593
#include <string.h>
char *search(char *s, char *t) {
    int len_s = strlen(s), len_t = strlen(t);
    for (int i = 0; i < len_s - len_t + 1; i++) {
        int flag = 1;
        for (int j = 0; j < len_t; j++) {
            if (s[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) return s + i;
    }
    return NULL;
}