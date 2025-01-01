// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805370650738688
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int maxn = (int)sqrt(n * 1.0) + 1, first = 0, len = 0;
    for (int i = 2; i <= maxn; i++) {
        int factor = 1, j = i;
        for (; j <= maxn; j++) {
            factor *= j;
            if (n % factor != 0) break;
        }
        if (j - i > len) {
            first = i;
            len = j - i;
        }
    }
    if (first == 0) {
        printf("1\n%d", n);
        return 0;
    }
    printf("%d\n", len);
    for (int i = first; i < first + len; i++) {
        if (i != first) printf("*");
        printf("%d", i);
    }
    return 0;
}