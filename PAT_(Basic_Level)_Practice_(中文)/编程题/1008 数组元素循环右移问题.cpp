// https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    m %= n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++) {
        if (cnt++ > 0) cout << " ";
        cout << v[n - m + i];
    }
    for (int i = 0; i < n - m; i++) {
        if (cnt++ > 0) cout << " ";
        cout << v[i];
    }
    return 0;
}
/* 链表法
#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
    node() : next(nullptr) {}
    node(int x) : data(x), next(nullptr) {}
};
void printList(node* head) {
    for (node* p = head->next; p != nullptr; p = p->next) {
        cout << p->data;
        if (p->next != nullptr) cout << " ";
    }
}
int main() {
    int n, m, x, cnt = 0;
    cin >> n >> m;
    m %= n;
    node *head = new node(), *r = head;
    for (int i = 0; i < n; i++) {
        cin >> x;
        r->next = new node(x);
        r = r->next;
    }
    if (m == 0) {
        printList(head);
        return 0;
    }
    node* p = head->next;
    for (; p != nullptr && ++cnt != n - m; p = p->next);
    for (r = p; r->next != nullptr; r = r->next);
    r->next = head->next;
    head->next = p->next;
    p->next = nullptr;
    printList(head);
    return 0;
}
*/