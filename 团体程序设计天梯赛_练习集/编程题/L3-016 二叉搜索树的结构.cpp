// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805047903240192
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    Node *left, *right;
    Node(int value = 0, Node *left = nullptr, Node *right = nullptr)
        : value(value), left(left), right(right) {}
};
struct Point {
    int x = INT_MAX, y = INT_MAX;
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
};
void buildTree(Node*& root, int x) {
    if (!root) {
        root = new Node(x);
    } else {
        if (x > root->value) {
            buildTree(root->right, x);
        } else {
            buildTree(root->left, x);
        }
    }
}
map<int, int> depthMap;
map<int, Point> childMap;
map<int, int> siblingMap;
void dfs(Node* root, int depth) {
    if (!root) return;
    depthMap[root->value] = depth;
    if (root->left) childMap[root->value].x = root->left->value;
    if (root->right) childMap[root->value].y = root->right->value;
    if (childMap[root->value].x != INT_MAX && childMap[root->value].y != INT_MAX) {
        siblingMap[root->left->value] = root->right->value;
        siblingMap[root->right->value] = root->left->value;
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main() {
    int n, k;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    Node* root = new Node(a[0]);
    for (int i = 1; i < n; ++i) {
        buildTree(root, a[i]);
    }
    dfs(root, 1);
    cin >> k;
    cin.ignore();
    while (k--) {
        string s;
        getline(cin, s);
        int x, y;
        if (s.find("root") != string::npos) {
            sscanf(s.c_str(), "%d is the root", &x);
            cout << (x == a[0] ? "Yes" : "No") << "\n";
        } else if (s.find("siblings") != string::npos) {
            sscanf(s.c_str(), "%d and %d are siblings", &x, &y);
            cout << (siblingMap.find(x) != siblingMap.end() && siblingMap[x] == y ? "Yes" : "No") << "\n";
        } else if (s.find("parent") != string::npos) {
            sscanf(s.c_str(), "%d is the parent of %d", &x, &y);
            cout << (childMap.find(x) != childMap.end() && (childMap[x].x == y || childMap[x].y == y) ? "Yes" : "No") << "\n";
        } else if (s.find("left") != string::npos) {
            sscanf(s.c_str(), "%d is the left child of %d", &x, &y);
            cout << (childMap.find(y) != childMap.end() && childMap[y].x == x ? "Yes" : "No") << "\n";
        } else if (s.find("right") != string::npos) {
            sscanf(s.c_str(), "%d is the right child of %d", &x, &y);
            cout << (childMap.find(y) != childMap.end() && childMap[y].y == x ? "Yes" : "No") << "\n";
        } else if (s.find("same") != string::npos) {
            sscanf(s.c_str(), "%d and %d are on the same level", &x, &y);
            cout << (depthMap.find(x) != depthMap.end() && depthMap.find(y) != depthMap.end() && depthMap[x] == depthMap[y] ? "Yes" : "No") << "\n";
        }
    }
    freeTree(root);
    return 0;
}