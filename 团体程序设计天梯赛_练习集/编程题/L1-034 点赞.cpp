// https://pintia.cn/problem-sets/994805046380707840/problems/994805098188750848
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
    int n, k, a, ans, MAX = -1, cnt[N] = {0};
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            cnt[a]++;
        }
    }
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] >= MAX) {
            MAX = cnt[i];
            ans = i;
        }
    }
    printf("%d %d", ans, MAX);
    return 0;
}