// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805065406070784
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
int n, pre[N], in[N], cnt = 0;
node *create(int prel, int prer, int inl, int inr) {
    if (prel > prer) return NULL;
    node *root = new node(pre[prel]);
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    root->left = create(prel + numleft + 1, prer, k + 1, inr);
    root->right = create(prel + 1, prel + numleft, inl, k - 1);
    return root;
}
void bfs(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *now = q.front();
        q.pop();
        printf("%d", now->data);
        if (++cnt < n) printf(" ");
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    node *root = create(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}