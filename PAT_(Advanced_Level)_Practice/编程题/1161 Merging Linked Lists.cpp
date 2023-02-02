// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1478635524918910976
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
    int adr, data, next;
} Node[maxn];
vector<node> l1, l2, ans;
void generateList(vector<node> &L, int head) {
    int p = head;
    while (p != -1) {
        L.push_back(Node[p]);
        p = Node[p].next;
    }
}

void printList(vector<node> L) {
    if (L.size() == 0) return;
    for (int i = 0; i < L.size() - 1; i++) {
        printf("%05d %d %05d\n", L[i].adr, L[i].data, L[i + 1].adr);
    }
    printf("%05d %d -1\n", L[L.size() - 1].adr, L[L.size() - 1].data);
}

int main() {
    int h1, h2, n, adr;
    cin >> h1 >> h2 >> n;
    for (int i = 0; i < n; i++) {
        cin >> adr;
        cin >> Node[adr].data >> Node[adr].next;
        Node[adr].adr = adr;
    }
    generateList(l1, h1);
    generateList(l2, h2);
    if (l1.size() < l2.size()) {
        swap(l1, l2);
    }
    if (l1.size() >= l2.size() * 2) {
        int cnt = 0, pos = l2.size() - 1;
        for (auto it : l1) {
            ans.push_back(it);
            if (++cnt % 2 == 0 && pos >= 0) {
                ans.push_back(l2[pos--]);
            }
        }
    }
    printList(ans);
    return 0;
}