// https://pintia.cn/problem-sets/994805046380707840/problems/1336215880692482056
#include <bits/stdc++.h>
using namespace std;
int Pop(stack<int> &s) {
    int tmp = s.top();
    s.pop();
    return tmp;
}
int main() {
    int n, n1, n2, x;
    char ch;
    scanf("%d", &n);
    stack<int> s1;
    stack<char> s2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s1.push(x);
    }
    for (int i = 0; i < n - 1; i++) {
        getchar();
        scanf("%c", &ch);
        s2.push(ch);
    }
    while (!s1.empty() && !s2.empty()) {
        int n1 = Pop(s1), n2 = Pop(s1);
        char op = s2.top();
        s2.pop();
        if (op == '/') {
            if (n1 == 0) {
                printf("ERROR: %d/%d\n", n2, n1);
                return 0;
            }
            s1.push(n2 / n1);
        } else if (op == '+') s1.push(n2 + n1);
        else if (op == '-') s1.push(n2 - n1);
        else s1.push(n2 * n1);
    }
    printf("%d", s1.top());
    return 0;
}