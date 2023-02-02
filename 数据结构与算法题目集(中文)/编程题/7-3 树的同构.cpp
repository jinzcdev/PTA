// https://pintia.cn/problem-sets/15/exam/problems/711
#include <bits/stdc++.h>
using namespace std;
struct node {
    char data;
    int left, right;
} bt1[15], bt2[15];
bool isIsomorphic(int a, int b) {
    if (a == -1 && b == -1) return true;
    if (a == -1 || b == -1) return false;
    if (bt1[a].data != bt2[b].data) return false;
    return (isIsomorphic(bt1[a].left, bt2[b].left) && isIsomorphic(bt1[a].right, bt2[b].right)) ||
           (isIsomorphic(bt1[a].left, bt2[b].right) && isIsomorphic(bt1[a].right, bt2[b].left));
}
void inorder(int root) {
    if (root == -1) return;
    inorder(bt2[root].left);
    cout << bt2[root].data << " ";
    inorder(bt2[root].right);
}
bool vis[15];
int main() {
    int n, m, a, b, root1 = -1, root2 = -1;
    char ch, left, right;
    cin >> n;
    fill(vis, vis + n, false);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c %c", &bt1[i].data, &left, &right);
        bt1[i].left = bt1[i].right = -1;
        if (left != '-') {
            bt1[i].left = left - '0';
            vis[left - '0'] = true;
        }
        if (right != '-') {
            bt1[i].right = right - '0';
            vis[right - '0'] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            root1 = i;
            break;
        }
    }
    cin >> m;
    fill(vis, vis + m, false);
    for (int i = 0; i < m; i++) {
        getchar();
        scanf("%c %c %c", &bt2[i].data, &left, &right);
        bt2[i].left = bt2[i].right = -1;
        if (left != '-') {
            bt2[i].left = left - '0';
            vis[left - '0'] = true;
        }
        if (right != '-') {
            bt2[i].right = right - '0';
            vis[right - '0'] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            root2 = i;
            break;
        }
    }
    printf("%s\n", isIsomorphic(root1, root2) ? "Yes" : "No");
    return 0;
}