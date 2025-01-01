// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=674
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, ans;
int mp[100][100];
int l[100], q[100], t[100];
int main() {
    int a, b, c, head = 0, tail = 0;
    scanf("%d%d", &n, &m);
    memset(mp, -1, sizeof(mp));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        mp[a][b] = c;
        l[b]++;
    }
    for (int i = 0; i < n; i++) {
        if (!l[i]) {
            q[tail++] = i;
        }
    }
    while (head < tail) {
        int temp = q[head++];
        if (t[temp] > ans) ans = t[temp];
        for (int i = 0; i < n; i++) {
            if (mp[temp][i] != -1) {
                l[i]--;
                if (!l[i]) q[tail++] = i;
                if (t[i] < t[temp] + mp[temp][i]) {
                    t[i] = t[temp] + mp[temp][i];
                }
            }
        }
    }
    if (tail < n)
        printf("Impossible");
    else
        printf("%d", ans);
}