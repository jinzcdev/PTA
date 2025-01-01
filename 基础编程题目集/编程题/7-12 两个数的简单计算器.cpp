// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=792
#include <cstdio>
int main() {
    int a, b, ans, flag = 1;
    char ch;
    scanf("%d %c %d", &a, &ch, &b);
    if (a < 0) {
        printf("-");
        a = -a;
    }
    switch (ch) {
        case '+': ans = a + b; break;
        case '-': ans = a - b; break;
        case '*': ans = a * b; break;
        case '/': ans = a / b; break;
        case '%': ans = a % b; break;
        default: 
            flag = 0;
            printf("ERROR");
    }
    if (flag) printf("%d", ans);
    return 0;
}