// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=307
double funcos( double e, double x ) {
    double ans = 1, item = 1, fac = 1;
    int flag = 1;
    for (int i = 2; item >= e; i += 2) {
        fac *= (i * (i - 1));
        item = pow(x, i) / fac;
        ans += (flag = -flag) * item;
    }
    return ans;
}