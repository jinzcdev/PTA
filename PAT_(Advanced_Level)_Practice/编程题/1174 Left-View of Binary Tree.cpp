// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173570
#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int _val) : val(_val) { left = right = nullptr; }
};
vector<int> pre, in, ans;
node* build(int prel, int prer, int inl, int inr) {
    if (prel > prer) return nullptr;
    node* root = new node(pre[prel]);
    int k = inl;
    while (k <= inr && in[k] != pre[prel]) k++;
    int numleft = k - inl;
    root->left = build(prel + 1, prel + numleft, inl, k - 1);
    root->right = build(prel + numleft + 1, prer, k + 1, inr);
    return root;
}
void dfs(node* root, int depth) {
    if (root == nullptr) return;
    if (depth == ans.size()) {
        ans.push_back(root->val);
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
int main() {
    int n;
    cin >> n;
    in.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> pre[i];
    node* root = build(0, n - 1, 0, n - 1);
    dfs(root, 0);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}