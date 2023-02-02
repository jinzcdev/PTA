// https://pintia.cn/problem-sets/14/exam/problems/799
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, f, y;
    cin >> n;
    for (f = 0; f <= 99; f++) {
        int k = (98 * f - n) % 199;
        if (k == 0) {
            printf("%d.%d", (98 * f - n) / 199, f);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}