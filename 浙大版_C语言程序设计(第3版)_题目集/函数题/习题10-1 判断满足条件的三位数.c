// https://pintia.cn/problem-sets/12/problems/351
int search( int n ) {
    int cnt = 0;
    for (int i = 101; i <= n; i++) {
        int maxCnt = 0, vis[10] = {0}, j = i;
        while (j != 0) {
            int t = j % 10;
            j /= 10;
            vis[t]++;
            if (vis[t] > maxCnt) maxCnt = vis[t];
        }
        if (maxCnt != 2) continue;
        int sqr = (int)sqrt(i * 1.0);
        if (sqr * sqr == i) cnt++;
    }
    return cnt;
}