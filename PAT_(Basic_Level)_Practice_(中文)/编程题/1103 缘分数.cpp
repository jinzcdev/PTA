// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478634171962896384
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    bool flag = false;
    scanf("%d%d", &m, &n);
    for (int x = m; x <= n; x++) {
        int a = 3 * x * x - 3 * x + 1;
        int sqr = (int)sqrt(a);
        if (sqr * sqr != a) continue;
        int b = (int)(sqrt(sqr) + 1);
        for (int i = b; i >= 2; i--) {
            if (sqr == i * i + (i - 1) * (i - 1)) {
                printf("%d %d\n", x, i);
                flag = true;
                break;
            }
        }
    }
    if (!flag) printf("No Solution");
    return 0;
}