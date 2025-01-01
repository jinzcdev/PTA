// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=841
#include <bits/stdc++.h>
using namespace std;
struct node {
    char msg[15];
    int pr;
    bool operator<(const node& a) const { return this->pr > a.pr; }
};
int main() {
    priority_queue<node> q;
    int n, pr;
    char cmd[5];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cmd);
        if (cmd[0] == 'G') {
            if (q.empty()) printf("EMPTY QUEUE!\n");
            else {
                printf("%s\n", q.top().msg);
                q.pop();
            }
        } else {
            node Node;
            scanf("%s%d", Node.msg, &Node.pr);
            q.push(Node);
        }
    }
    return 0;
}