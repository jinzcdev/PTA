// https://pintia.cn/problem-sets/16/problems/668
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
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
}
void R(node *&root) {
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
}
void insert(node *&root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) {
        insert(root->left, x);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                R(root);
            } else {
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->right, x);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == -1) {
                L(root);
            } else {
                R(root->right);
                L(root);
            }
        }
    }
}
int main() {
    int n, x;
    scanf("%d", &n);
    node *root = NULL;
    while (n--) {
        scanf("%d", &x);
        insert(root, x);
    }
    printf("%d", root->data);
    return 0;
}