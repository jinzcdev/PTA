// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805049870368768
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, id;
    node *left, *right;
    node(int x, int id) : data(x), id(id) {
        left = right = NULL;
    }
};
void insert(node *&root, int x, int id) {
    if (root == NULL) {
        root = new node(x, id);
        return;
    }
    if (x > root->data) insert(root->left, x, id * 2);
    else insert(root->right, x, id * 2 + 1);
}
int bfs(node *root, int n) {
    queue<node*> q;
    q.push(root);
    vector<int> v;
    int cnt = 0, id = 1, flag = 1;
    while (!q.empty()) {
        node *now = q.front();
        q.pop();
        if (id++ != now->id) flag = 0;
        if (cnt++ > 0) printf(" ");
        printf("%d", now->data);
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
    return flag;
}
int main() {
    int n, x;
    node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(root, x, 1);
    }
    printf("\n%s", bfs(root, n) ? "YES" : "NO");
    return 0;
}