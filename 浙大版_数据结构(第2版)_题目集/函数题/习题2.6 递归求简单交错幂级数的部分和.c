// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=5804
double fn(double x, int n) {
    if (n == 1) return x;
    return x - x * fn(x, n - 1);
}