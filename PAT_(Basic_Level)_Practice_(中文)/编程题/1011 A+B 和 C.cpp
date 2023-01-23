// https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952
#include <cstdio>
int main() {
    int tcase = 1, T;
    scanf("%d", &T);
    while (T--) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: true\n", tcase++);
        } else {
            printf("Case #%d: false\n", tcase++);
        }
    }
    return 0;
}