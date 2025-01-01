// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=5806
double dist(double h, double p) {
    double sum = 0.0, tmp = h * p;
    while (tmp >= TOL) {
        sum += tmp;
        tmp *= p;
    }
    sum *= 2;
    return sum + h;
}