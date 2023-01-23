// https://pintia.cn/problem-sets/15/problems/857
#include <bits/stdc++.h>
using namespace std;
struct node {
    string val;
    vector<node *> link;
    int isdir = 0;
    node(string _val, bool _isdir) : val(_val), isdir(_isdir){};
};
bool cmp(node *&a, node *&b) {
    return a->isdir != b->isdir ? a->isdir > b->isdir : a->val < b->val;
}
void insert(node *root, string path) {
    if (path.length() == 0) return;
    int k = path.find_first_of('\\');
    if (k == string::npos) {
        node *p = new node(path, 0);
        root->link.push_back(p);
    } else {
        node *p = new node(path.substr(0, k), 1);
        node *q = NULL;
        for (int i = 0; i < root->link.size(); i++) {
            if (root->link[i]->val == p->val) {
                q = root->link[i];
                break;
            }
        }
        if (q == NULL) {
            root->link.push_back(p);
            insert(p, path.substr(k + 1));
        } else {
            insert(q, path.substr(k + 1));
        }
    }
}
void dfs(node *root, int depth) {
    if (root == NULL) return;
    for (int i = 0; i < depth * 2; i++) printf(" ");
    cout << root->val << endl;
    sort(root->link.begin(), root->link.end(), cmp);
    for (auto it : root->link) {
        dfs(it, depth + 1);
    }
}
int main() {
    int n;
    string path;
    scanf("%d", &n);
    node *root = new node("root", 1);
    while (n--) {
        cin >> path;
        insert(root, path);
    }
    dfs(root, 0);
    return 0;
}