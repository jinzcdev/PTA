// https://pintia.cn/problem-sets/15/exam/problems/843
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = nullptr; }
};
int n, cnt = 0;
void insert(node*& root, int x, bool is_mirror) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) insert(is_mirror ? root->right : root->left, x, is_mirror);
    else insert(is_mirror ? root->left : root->right, x, is_mirror);
}
void preOrder(node* root, vector<int>& v, bool is_mirror) {
    if (root == NULL) return;
    v.push_back(root->data);
    preOrder(is_mirror ? root->right : root->left, v, is_mirror);
    preOrder(is_mirror ? root->left : root->right, v, is_mirror);
}
void postOrder(node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d", root->data);
    if (++cnt < n) printf(" ");
}
int main() {
    scanf("%d", &n);
    vector<int> v(n);
    node *root = nullptr, *m_root = nullptr;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        insert(root, v[i], false);
        insert(m_root, v[i], true);
    }
    vector<int> pre, m_pre;
    preOrder(root, pre, false);
    preOrder(root, m_pre, true);
    if (v != pre && v != m_pre) printf("NO\n");
    else {
        printf("YES\n");
        postOrder(v == pre ? root : m_root);
    }
    return 0;
}