// https://pintia.cn/problem-sets/434/problems/6495
#include <bits/stdc++.h>
using namespace std;
struct node {
    int in, cost;
};
int main() {
    int n, k, a, b, totalWait = 0, maxWait = 0;
    scanf("%d", &n);
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].in, &v[i].cost);
        if (v[i].cost > 60) v[i].cost = 60;
    }
    scanf("%d", &k);
    vector<int> finish(k, 0), cnt(k, 0);
    for (int i = 0; i < n; i++) {
        int winNo = -1, MIN = 999999, minWinNo = 0;
        for (int j = 0; j < k; j++) {
            if (finish[j] <= v[i].in) {
                winNo = j;
                break;
            }
            if (finish[j] - v[i].in < MIN) {
                MIN = finish[j] - v[i].in;
                minWinNo = j;
            }
        }
        if (winNo == -1) winNo = minWinNo;
        cnt[winNo]++;
        if (finish[winNo] <= v[i].in) finish[winNo] = v[i].in + v[i].cost;
        else {
            int wait = finish[winNo] - v[i].in;
            maxWait = max(wait, maxWait);
            totalWait += wait;
            finish[winNo] += v[i].cost;
        }
    }
    int lastFinish = 0;
    for (int i = 0; i < k; i++) lastFinish = max(finish[i], lastFinish);
    printf("%.1f %d %d\n", totalWait * 1.0 / n, maxWait, lastFinish);
    for (int i = 0; i < k; i++) {
        if (i != 0) printf(" ");
        printf("%d", cnt[i]);
    }
    return 0;
}

