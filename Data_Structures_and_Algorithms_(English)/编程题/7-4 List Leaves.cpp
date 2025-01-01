// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=666
#include <bits/stdc++.h>
using namespace std;
struct node {
    int left = -1, right = -1;
} Node[15];
void bfs(int root) {
    queue<int> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (Node[now].left != -1) q.push(Node[now].left);
        if (Node[now].right != -1) q.push(Node[now].right);
        if (Node[now].left == -1 && Node[now].right == -1) {
            if (cnt++ > 0) printf(" ");
            printf("%d", now);
        }
    }
}
int main() {
    int n, root = 0, vis[15] = {0};
    char a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &a, &b);
        if (a != '-') {
            Node[i].left = a - '0';
            vis[a - '0'] = 1;
        }
        if (b != '-') {
            Node[i].right = b - '0';
            vis[b - '0'] = 1;
        }
    }
    while (vis[root]) root++;
    bfs(root);
    return 0;
}