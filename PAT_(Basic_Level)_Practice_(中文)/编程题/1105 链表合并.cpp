// https://pintia.cn/problem-sets/994805260223102976/problems/1478634321389170688
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    int data, adr, next;
} L[N];
int main() {
    int head1, head2, n, adr, k = 0;
    scanf("%d%d%d", &head1, &head2, &n);
    while (n--) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l1, l2, l;
    for (int p = head1; p != -1; p = L[p].next) l1.push_back(L[p]);
    for (int p = head2; p != -1; p = L[p].next) l2.push_back(L[p]);
    if (l1.size() < l2.size()) swap(l1, l2);
    for (int i = 0; i < l1.size(); i++) {
        l.push_back(l1[i]);
        if (i % 2 == 1 && k < l2.size()) {
            l.push_back(l2[l2.size() - k - 1]);
            k++;
        }
    }
    for (int i = 0; i < l.size() - 1; i++)
        printf("%05d %d %05d\n", l[i].adr, l[i].data, l[i + 1].adr);
    printf("%05d %d -1", l[l.size() - 1].adr, l[l.size() - 1].data);
    return 0;
}