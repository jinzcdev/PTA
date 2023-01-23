// https://pintia.cn/problem-sets/994805260223102976/problems/994805262622244864
#include <cstdio>
int main() {
    char a[5];
    getchar();
    while (scanf("%s", a) != EOF)
        if (a[2] == 'T') printf("%d", a[0] - 'A' + 1);
    return 0;
}