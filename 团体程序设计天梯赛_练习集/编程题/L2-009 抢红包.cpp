// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805066890854400
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct node {
    int id, cnt, amount;
} Node[N];
bool cmp(node &a, node &b) {
    if (a.amount != b.amount) return a.amount > b.amount;
    return a.cnt != b.cnt ? a.cnt > b.cnt : a.id < b.id;
}
int main() {
    int n, k, id, amount;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        Node[i].id = i;
        scanf("%d", &k);
        while (k--) {
            scanf("%d%d", &id, &amount);
            Node[i].amount -= amount;
            Node[id].cnt++;
            Node[id].amount += amount;
        }
    }
    sort(Node + 1, Node + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        printf("%d %.2f\n", Node[i].id, Node[i].amount / 100.0);
    }
    return 0;
}