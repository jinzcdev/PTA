// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805300404535296
#include <cstdio>
#include <cstring>
char n[1010];
int ans[10] = {0};
int main() {
    scanf("%s", n);
    int len = strlen(n);
    for (int i = 0; i < len; i++) ans[n[i] - '0']++;
    for (int i = 0; i < 10; i++)
        if (ans[i] != 0) printf("%d:%d\n", i, ans[i]);
    return 0;
}