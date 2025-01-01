// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805346776760320
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    int adr, data, next;
} Node[maxn];
int main() {
    int head, n, k, adr;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &Node[adr].data, &Node[adr].next);
        Node[adr].adr = adr;
    } 
    vector<node> l, l1, l2, l3;
    int p = head;
    while (p != -1) {
        l.push_back(Node[p]);
        p = Node[p].next;
    }
    for (int i = 0; i < l.size(); i++) {
        if (l[i].data < 0) l1.push_back(l[i]);
        else if (l[i].data <= k) l2.push_back(l[i]);
        else l3.push_back(l[i]);
    }
    l.clear();
    for (int i = 0; i < l1.size(); i++) l.push_back(l1[i]);
    for (int i = 0; i < l2.size(); i++) l.push_back(l2[i]);
    for (int i = 0; i < l3.size(); i++) l.push_back(l3[i]);
    for (int i = 0; i < l.size() - 1; i++) {
        printf("%05d %d %05d\n", l[i].adr, l[i].data, l[i + 1].adr);
    }
    printf("%05d %d -1\n", l[l.size() - 1].adr, l[l.size() - 1].data);
    return 0;
}