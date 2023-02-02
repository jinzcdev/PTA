// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805118568873984
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, maxA, maxB, cntA = 0, cntB = 0, a, b, c, d;
    scanf("%d%d%d", &maxA, &maxB, &n);
    while (n--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int tmp = a + c;
        if ((b == tmp && d == tmp) || (b != tmp && d != tmp)) continue;
        if (b == tmp && ++cntA > maxA) {
            printf("A\n%d", cntB);
            break;
        } else if (d == tmp && ++cntB > maxB) {
            printf("B\n%d", cntA);
            break;
        }
    }
    return 0;
}