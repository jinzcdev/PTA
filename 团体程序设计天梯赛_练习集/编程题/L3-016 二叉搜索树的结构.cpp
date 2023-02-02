// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805047903240192
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
unordered_map<int, int> parent, lchild, rchild, level;
void insert(node *&root, int x, int father, int depth) {
    if (root == NULL) {
        root = new node(x);
        level[x] = depth;
//         if (father != -1) {
            parent[x] = father;
            if (x < father) lchild[father] = x;
            else rchild[father] = x;
//         }
        return;
    }
    if (x < root->data) insert(root->left, x, root->data, depth + 1);
    else insert(root->right, x, root->data, depth + 1);
}
void parseNumber(string s, int &a, int &b) {
    vector<int> v;
    string it = "";
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) || s[i] == '-') it += s[i];
        if ((!isdigit(s[i]) && s[i] != '-') || i == s.length() - 1) {
            if (it != "") {
                v.push_back(stoi(it));
                it = "";
            }
        }
    }
    a = v[0];
    b = v.size() > 1 ? v[1] : -1;
}
int main() {
    int n, m, x, a, b;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(root, x, -1, 1);
    }
    scanf("%d", &m);
    getchar();
    string s;
    while (m--) {
        bool flag = false;
        getline(cin, s);
        parseNumber(s, a, b);
        if (*s.rbegin() == 't') flag = root->data == a;
        else if (*s.rbegin() == 's') flag = parent[a] == parent[b];
        else if (*s.rbegin() == 'l') flag = level[a] == level[b];
        else if (s.find('p') != string::npos) flag = a == parent[b];
        else if (s.find('r') != string::npos) flag = a == rchild[b];
        else flag = a == lchild[b];
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}