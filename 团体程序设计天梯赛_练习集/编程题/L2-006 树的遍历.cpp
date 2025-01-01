// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805069361299456
#include <bits/stdc++.h>
using namespace std;
const int N = 40;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
int in[N], post[N];
node* create(int postl, int postr, int inl, int inr) {
    if (postl > postr) return NULL;
    node* root = new node(post[postr]);
    int k = inl;
    while (k <= inr && post[postr] != in[k]) k++;
    int numleft = k - inl;
    root->left = create(postl, postl + numleft - 1, inl, k - 1);
    root->right = create(postl + numleft, postr - 1, k + 1, inr);
    return root;
}
void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        if (cnt++ > 0) printf(" ");
        printf("%d", now->data);
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
}
int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    node* root = create(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}