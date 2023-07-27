#include <bits/stdc++.h>
using namespace std;
struct LNode {
    int val;
    LNode *left, *right;
    LNode() { left = right = nullptr; };
    LNode(int _val) {
        val = _val;
        left = right = nullptr;
    }
};
class BList {
   public:
    LNode *head, *tail;
    int size = 0;
    BList() {
        head = new LNode();
        tail = new LNode();
        head->right = tail;
        tail->left = head;
    }

    void insertHead(LNode *node) {
        node->right = head->right;
        head->right->left = node;
        node->left = head;
        head->right = node;
        size++;
    }
    void removeNode(LNode *node) {
        if (size == 0) return;
        node->left->right = node->right;
        node->right->left = node->left;
        size--;
    }
    LNode *popTail() {
        if (size == 0) {
            return nullptr;
        }
        LNode *p = tail->left;
        removeNode(p);
        // 之前因为在这里 size-- 导致多减了一个 1
        return p;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> v(m), ans;
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }
    BList list = BList();
    unordered_map<int, LNode *> hash;
    for (int i = 0; i < m; i++) {
        int x = v[i];
        if (hash.find(x) != hash.end()) {
            LNode *node = hash[x];
            if (node == list.head) {
                continue;
            }
            list.removeNode(node);
            list.insertHead(node);
        } else {
            if (list.size >= n) {
                LNode *tail = list.popTail();
                ans.push_back(tail->val);
                hash.erase(tail->val);
            }
            LNode *node = new LNode(x);
            list.insertHead(node);
            hash[x] = node;
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}