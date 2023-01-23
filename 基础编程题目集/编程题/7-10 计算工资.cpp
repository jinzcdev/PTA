// https://pintia.cn/problem-sets/14/problems/790
#include <cstdio>
double solve(int year, int t) {
    int salary = year < 5 ? 30 : 50;
    double sum = 0.0;
    if (t <= 40) sum = salary * t;
    else sum = salary * (40 + 1.5 * (t - 40));
    return sum;
}
int main() {
    int year, t;
    scanf("%d%d", &year, &t);
    printf("%.2f", solve(year, t));
    return 0;
}