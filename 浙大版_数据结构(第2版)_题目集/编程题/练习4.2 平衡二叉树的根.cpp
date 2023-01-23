// https://pintia.cn/problem-sets/434/problems/6103
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
int getHeight(node *root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(node *root) {
    return getHeight(root->left) - getHeight(root->right);
}
void L(node *&root) {
    node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    root = tmp;
}
void R(node *&root) {
    node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    root = tmp;
}
void insert(node *&root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) {
        insert(root->left, x);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) != 1) L(root->left);
            R(root);
        }
    } else {
        insert(root->right, x);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) != -1) R(root->right);
            L(root);
        }
    }
}
int main() {
    int n, a;
    node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        insert(root, a);
    }
    printf("%d", root->data);
    return 0;
}