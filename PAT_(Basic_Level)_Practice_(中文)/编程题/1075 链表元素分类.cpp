// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805262953594880
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
struct node {
    int adr, data, next;
} Node[N];
int main() {
    int start, n, k, adr, data, next;
    scanf("%d%d%d", &start, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &adr, &data, &next);
        Node[adr] = {adr, data, next};
    }
    vector<node> l1, l2, l3;
    for (int p = start; p != -1; p = Node[p].next) {
        if (Node[p].data < 0) l1.push_back(Node[p]);
        else if (Node[p].data <= k) l2.push_back(Node[p]);
        else l3.push_back(Node[p]);
    }
    l1.insert(l1.end(), l2.begin(), l2.end());
    l1.insert(l1.end(), l3.begin(), l3.end());
    if (l1.size() == 0) return 0;
    for (int i = 0; i < l1.size() - 1; i++)
        printf("%05d %d %05d\n", l1[i].adr, l1[i].data, l1[i + 1].adr);
    printf("%05d %d -1\n", (*l1.rbegin()).adr, (*l1.rbegin()).data);
    return 0;
}

/*
#include <stdio.h>
int main() {
    int data[100000] = {0}, next[100000] = {0}, firstaddr, addr, lastaddr = -1, N, K;
    scanf("%d %d %d", &firstaddr, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &addr);
        scanf("%d %d", data + addr, next + addr);
    }
    for (int i = 0; i < 3; i++) {
        for (addr = firstaddr; addr != -1; addr = next[addr]) {
            if ((i == 0 && data[addr] < 0) ||
                (i == 1 && 0 <= data[addr] && data[addr] <= K) ||
                (i == 2 && data[addr] > K)) {
                if (lastaddr != -1) printf(" %05d\n", addr);
                printf("%05d %d", addr, data[addr]);
                lastaddr = addr;
            }
        }
    }
    printf(" -1");
    return 0;
}
*/