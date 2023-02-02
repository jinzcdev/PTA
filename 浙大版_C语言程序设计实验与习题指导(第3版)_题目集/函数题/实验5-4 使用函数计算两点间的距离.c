// https://pintia.cn/problem-sets/13/exam/problems/462
double dist(double x1, double y1, double x2, double y2) {
    double a = fabs(x1 - x2), b = fabs(y1 - y2);
    return sqrt(a * a + b * b);
}