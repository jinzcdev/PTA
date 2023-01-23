// https://pintia.cn/problem-sets/994805046380707840/problems/994805090748055552
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char ch;
    double a;
    cin >> n;
    while (n--) {
        getchar();
        scanf("%c %lf", &ch, &a);
        if (ch == 'M') printf("%.2f\n", a / 1.09);
        else printf("%.2f\n", a * 1.09);
    }
    return 0;
}