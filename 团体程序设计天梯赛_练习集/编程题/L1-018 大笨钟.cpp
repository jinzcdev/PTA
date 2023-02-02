// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805119944605696
#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, m, t;
    scanf("%d:%d", &h, &m);
    t = h * 60 + m;
    if (t >= 0 && t <= 12 * 60) {
        printf("Only %02d:%02d.  Too early to Dang.\n", h, m);
    } else {
        int num = (m == 0 ? h - 12 : h - 11);
        while (num--) printf("Dang");
    }
    return 0;
}