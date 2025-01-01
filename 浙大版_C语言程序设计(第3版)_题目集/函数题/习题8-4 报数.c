// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=337
void CountOff(int n, int m, int out[]) {
    int is_out[1000] = {0}, cnt = 0, d = 0;
    for (int i = 0; i < n && cnt != n; i = (i + 1) % n) {
        if (is_out[i]) {
            continue;
        } else if (++d % m == 0){
            is_out[i] = 1;
            out[i] = ++cnt;
        }
    }
}
