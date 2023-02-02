// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805135224455168
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = a, cnt = 0; i <= b; i++) {
        printf("%5d", i);
        sum += i;
        if (++cnt % 5 == 0) printf("\n");
    }
    if ((b - a + 1) % 5 != 0) printf("\n");
    printf("Sum = %d", sum);
    return 0;
}