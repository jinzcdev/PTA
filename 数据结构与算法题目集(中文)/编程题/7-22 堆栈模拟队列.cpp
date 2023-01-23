// https://pintia.cn/problem-sets/15/problems/837
#include <bits/stdc++.h>
using namespace std;
void move(stack<int> &s1, stack<int> &s2) {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
}
int main() {
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    if (n1 > n2) swap(n1, n2);
    getchar();
    stack<int> s1, s2;
    char op;
    int x;
    while (op = getchar(), op != 'T') {
        if (op == 'A') {
            scanf(" %d ", &x);
            if (s1.size() < n1) s1.push(x);
            else if (s1.size() == n1 && s2.size() != 0) printf("ERROR:Full\n");
            else {
                move(s1, s2);
                s1.push(x);
            }
        } else {
            getchar();  // 接收后一个空格
            if (!s2.empty()) {
                printf("%d\n", s2.top());
                s2.pop();
            } else if (s1.empty()) {
                printf("ERROR:Empty\n");
            } else {
                move(s1, s2);
                printf("%d\n", s2.top());
                s2.pop();
            }
        }
    }
    return 0;
}