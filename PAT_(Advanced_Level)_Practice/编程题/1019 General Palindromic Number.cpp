// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805487143337984
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, b;
    scanf("%d%d", &n, &b);
    vector<int> d;
    for (; n != 0; n /= b) d.push_back(n % b);
    int i = 0, len = d.size();
    while (i < len / 2 && d[i] == d[len - i - 1]) i++;
    printf("%s\n", i == len / 2 ? "Yes" : "No");
    for (int i = len - 1; i >= 0; i--) {
        if (i != len - 1) printf(" ");
        printf("%d", d[i]);
    }
    return 0;
}