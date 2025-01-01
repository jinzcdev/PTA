// https://pintia.cn/problem-sets/13/exam/problems/type/7?problemSetProblemId=543
#include <stdio.h>
int main() {
    char s[35];
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < 32; i += 8) {
        int x = 0;
        for (int j = 0; j < 8; j++) {
            x = x * 2 + (s[i + j] - '0');
        }
        printf("%d", x);
        if (++cnt < 4) printf(".");
    }
    return 0;
}
