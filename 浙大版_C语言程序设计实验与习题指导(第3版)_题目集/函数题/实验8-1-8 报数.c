// https://pintia.cn/problem-sets/13/problems/549
void CountOff(int n, int m, int out[]) {
    int idx = 0, num = 0, i = 0, is_out[MAXN] = {0}, cnt = 0;
    while (cnt != n) {
        if (!is_out[i]) {
            if (++num % m == 0) {
                is_out[i] = 1;
                out[i] = ++cnt;
            }
        }
        i = (++i) % n;
    }
}
