// https://pintia.cn/problem-sets/434/exam/problems/6101
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int post[N], in[N], n;
void preOrder(int postl, int postr, int inl, int inr) {
    if (postl > postr) return;
    int k = inl;
    while (k <= inr && in[k] != post[postr]) k++;
    int numleft = k - inl;
    printf(" %d", post[postr]);
    preOrder(postl, postl + numleft - 1, inl, k - 1);
    preOrder(postl + numleft, postr - 1, k + 1, inr);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    printf("Preorder:");
    preOrder(0, n - 1, 0, n - 1);
    return 0;
}