// https://pintia.cn/problem-sets/994805260223102976/problems/1478634052026146816
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    int d;
    cin >> a >> d;
    b = a.substr(a.length() - d) + a.substr(0, a.length() - d);
    printf("%.2f", stod(b) / stod(a));
    return 0;
}