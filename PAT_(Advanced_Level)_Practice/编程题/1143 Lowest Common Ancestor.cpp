// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343727501312
// 通用解法
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int _x) : data(_x) { left = right = nullptr; }
};
vector<int> pre, in;
node *create(int prel, int prer, int inl, int inr) {
    if (prel > prer) return nullptr;
    node *root = new node(pre[prel]);
    int k = inl;
    while (k <= inr && in[k] != pre[prel]) k++;
    int numleft = k - inl;
    root->left = create(prel + 1, prel + numleft, inl, k - 1);
    root->right = create(prel + numleft + 1, prer, k + 1, inr);
    return root;
}
node *lowestCommonAncestor(node *root, int p, int q) {
    if (root == nullptr || root->data == p || root->data == q) {
        return root;
    }
    node *left = lowestCommonAncestor(root->left, p, q);
    node *right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
        return root;
    }
    return left == nullptr ? right : left;
}
int main() {
    int n, m, a, b;
    unordered_map<int, bool> exist;
    cin >> m >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        exist[pre[i]] = true;
    }
    in = pre;
    sort(in.begin(), in.end());
    node *root = create(0, n - 1, 0, n - 1);
    while (m--) {
        cin >> a >> b;
        if (!exist[a] && !exist[b]) printf("ERROR: %d and %d are not found.\n", a, b);
        else if (!exist[a]) printf("ERROR: %d is not found.\n", a);
        else if (!exist[b]) printf("ERROR: %d is not found.\n", b);
        else  {
            node *ans = lowestCommonAncestor(root, a, b);
            if (ans->data == a || ans->data == b) printf("%d is an ancestor of %d.\n", ans->data, ans->data == a ? b : a);
            else printf("LCA of %d and %d is %d.\n", a, b, ans->data);
        }
    }
    return 0;
}
/*
// 根据二叉搜索树的特性解题
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mp;
int main() {
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; j++) {
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        } 
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}
*/