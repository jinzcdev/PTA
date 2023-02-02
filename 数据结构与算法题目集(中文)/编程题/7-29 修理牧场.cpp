// https://pintia.cn/problem-sets/15/exam/problems/856
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, sum = 0;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push(x);
    }
    while (q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        sum += a + b;
        q.push(a + b);
    }
    printf("%d", sum);
    return 0;
}