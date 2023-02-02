// https://pintia.cn/problem-sets/13/exam/problems/574
int search(int n) {
    int cnt = 0;
    for (int x = 101; x <= n; x++) {
        int sqr = (int)sqrt(x);
        if (sqr * sqr != x) continue;
        int tmp = x, a[3] = {0};
        for (int i = 0; i < 3; i++) {
            a[i] = tmp % 10;
            tmp /= 10;
        }
        if ((a[0] == a[1] && a[0] != a[2]) || (a[0] == a[2] && a[0] != a[1]) ||
            (a[1] == a[2] && a[0] != a[1])) {
            cnt++;
        }
    }
    return cnt;
}