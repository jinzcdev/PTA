// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1336215880692482050
#include <cstdio>
int main() {
    double a, b;
    int flag;
    scanf("%lf%d%lf", &a, &flag, &b);
    double c = (flag == 0 ? 2.455 : 1.26);
    double ans = a * c / b;
    if (ans > 1.0) printf("%.2f T_T\n", a * c);
    else printf("%.2f ^_^\n", a * c);
    return 0;
}