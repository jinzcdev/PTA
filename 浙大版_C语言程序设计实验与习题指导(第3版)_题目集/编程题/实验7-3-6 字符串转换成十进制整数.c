// https://pintia.cn/problem-sets/13/exam/problems/527
#include <ctype.h>
#include <stdio.h>
int main() {
    int ans = 0, flag = 0, hasNeg = 0, isNeg = 0;
    char ch;
    while (ch = getchar(), ch != '#') {
        if (ch == '-') hasNeg = 1;
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') ||
            (ch >= 'A' && ch <= 'F')) {
            if (flag == 0) {
                flag = 1;
                if (hasNeg) isNeg = 1;
            }
            if (ch >= '0' && ch <= '9') ans = ans * 16 + (ch - '0');
            if ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')) {
                ch = tolower(ch);
                ans = ans * 16 + (ch - 'a' + 10);
            }
        }
    }
    if (isNeg) printf("-");
    printf("%d", ans);
    return 0;
}