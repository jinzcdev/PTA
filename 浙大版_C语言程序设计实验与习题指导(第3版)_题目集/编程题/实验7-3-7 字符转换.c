// https://pintia.cn/problem-sets/13/exam/problems/type/7?problemSetProblemId=528
#include <stdio.h>
#include <string.h>
int main() {
    char s[90];
    gets(s);
//    scanf("%s", s);
    int ans = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
        }
    }
    printf("%d", ans);
    return 0;
}