// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=786
#include <cstdio>
int main() {
    double d1, d2;
    int i;
    char ch;
    scanf("%lf %d", &d1, &i);
    getchar();
    scanf("%c %lf", &ch, &d2);
    printf("%c %d %.2f %.2f", ch, i, d1, d2);
    return 0;
}