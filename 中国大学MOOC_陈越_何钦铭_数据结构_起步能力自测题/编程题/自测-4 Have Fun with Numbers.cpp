// https://pintia.cn/problem-sets/17/exam/problems/type/7?problemSetProblemId=263
#include <bits/stdc++.h>
const int N = 25;
char d[N];
int cntMap[10] = {0}, ans[N];
int main() {
    scanf("%s", d);
    int cnt = 0, len = strlen(d), k = 0;
    for (int i = len - 1; i >= 0; i--) {
        cntMap[d[i] - '0']++;
        int tmp = (d[i] - '0') * 2 + k;
        ans[cnt++] = tmp % 10;
        k = tmp / 10;
    }
    if (k != 0) ans[cnt++] = k;
    bool flag = true;
    for (int i = 0; i < cnt; i++) {
        if (--cntMap[ans[i]] < 0) {
            flag = false;
            break;
        }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}