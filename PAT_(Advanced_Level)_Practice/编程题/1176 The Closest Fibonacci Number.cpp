// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542720
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a = 0, b = 1, t;
    while (!(n >= a && n <= b)) {
        t = b;
        b = a + b;
        a = t;
    }
    int da = abs(n - a), db = abs(n - b);
    printf("%d", da <= db ? a : b);
    return 0;
}