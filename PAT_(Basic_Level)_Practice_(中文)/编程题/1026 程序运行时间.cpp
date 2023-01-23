// https://pintia.cn/problem-sets/994805260223102976/problems/994805295203598336
#include <cstdio>
int main() {
    int c1, c2, d, s;
    scanf("%d%d", &c1, &c2);
    d = c2 - c1;
    s = d % 100 >= 50 ? d / 100 + 1 : d / 100;
    printf("%02d:%02d:%02d", s / 3600, (s % 3600) / 60, s % 60);
    return 0;
}