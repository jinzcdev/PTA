// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478636026017230848
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
vector<int> pre, ans;
int getmin(int left, int right) {
    int pos = left;
    for (int i = left; i <= right; i++)
        if (pre[i] < pre[pos]) pos = i;
    return pos;
}
node* create(int prel, int prer) {
    if (prel > prer) return NULL;
    int k = getmin(prel, prer);
    node* root = new node(pre[k]);
    root->left = create(prel, k - 1);
    root->right = create(k + 1, prer);
    return root;
}
void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        ans.push_back(now->data);
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
}
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pre.push_back(x);
    }
    node* root = create(0, n - 1);
    bfs(root);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}