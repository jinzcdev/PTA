// https://pintia.cn/problem-sets/13/exam/problems/464
int IsSquare(int n) {
    if (n < 0) return 0;
    int i = 0;
    for (; i * i < n; i++);
    return i * i == n;
}