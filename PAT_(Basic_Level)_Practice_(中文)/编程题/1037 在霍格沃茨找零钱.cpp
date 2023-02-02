// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805284923359232
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3], b[3];
    scanf("%d.%d.%d %d.%d.%d", &b[0], &b[1], &b[2], &a[0], &a[1], &a[2]);
    if (b[0] * 10000 + b[1] * 100 + b[2] > a[0] * 10000 + a[1] * 100 + a[2]) {
        printf("-");
        swap(a, b);
    }
    for (int i = 0; i < 3; i++) a[i] -= b[i];
    if (a[2] < 0) {
        a[2] += 29;
        a[1]--;
    }
    if (a[1] < 0) {
        a[1] += 17;
        a[0]--;
    }
    printf("%d.%d.%d", a[0], a[1], a[2]);
    return 0;
}