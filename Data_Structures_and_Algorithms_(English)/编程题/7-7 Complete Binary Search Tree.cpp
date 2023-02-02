// https://pintia.cn/problem-sets/16/exam/problems/669
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int in[N], cbt[N], n, len = 1;
void inorder(int i) {
    if (i > n) return;
    inorder(i * 2);
    cbt[i] = in[len++];
    inorder(i * 2 + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &in[i]);
    sort(in + 1, in + n + 1);
    inorder(1);
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", cbt[i]);
    }
    return 0;
}