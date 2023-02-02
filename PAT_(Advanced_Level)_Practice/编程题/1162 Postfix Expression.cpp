// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1478635599577522176
#include <iostream>
#include <string>
using namespace std;
const int maxn = 25;
bool vis[maxn];
struct node {
    string v;
    int lc, rc;
} Node[maxn];
int n;

bool isOperator(string str) {
    return str == "-" || str == "/" || str == "*" || str == "+";
}

void postOrder(int root) {
    if (root == -1) return;
    cout << "(";
    postOrder(Node[root].lc);
    if (isOperator(Node[root].v) && Node[root].lc == -1) {
        cout << Node[root].v;
        postOrder(Node[root].rc);
    } else {
        postOrder(Node[root].rc);
        cout << Node[root].v;
    }
    cout << ")";
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Node[i].v >> Node[i].lc >> Node[i].rc;
        if (Node[i].lc != -1) vis[Node[i].lc] = true;
        if (Node[i].rc != -1) vis[Node[i].rc] = true;
    }
    int R;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            R = i;
            break;
        }
    }
    postOrder(R);
    return 0;
}
