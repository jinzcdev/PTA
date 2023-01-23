// https://pintia.cn/problem-sets/994805260223102976/problems/994805267860930560
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, Max = -1;
    scanf("%d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        Max = max(Max, a * a + b * b);
    }
    printf("%.2f", sqrt(Max * 1.0));
    return 0;
}