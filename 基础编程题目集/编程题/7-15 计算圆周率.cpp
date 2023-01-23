// https://pintia.cn/problem-sets/14/problems/795
#include <bits/stdc++.h>
using namespace std;
int main() {
    double error, sum = 1, tmp = 1.0;
    cin >> error;
    for (int i = 1; tmp >= error; i++) {
        tmp *= (i * 1.0 / (2 * i + 1));
        sum += tmp;
    }
    printf("%.6f", sum * 2.0);
    return 0;
}