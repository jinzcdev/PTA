// https://pintia.cn/problem-sets/434/exam/problems/type/7?problemSetProblemId=6477
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    return 0;
}