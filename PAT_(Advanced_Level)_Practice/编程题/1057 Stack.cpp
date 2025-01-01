// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805417945710592
#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))
using namespace std;
const int maxn = 100010;
int c[maxn] = {0};
stack<int> s;

void add(int x, int v) {
    while (x < maxn) {
        c[x] += v;
        x += lowbit(x);
    }
}
int getSum(int x) {
    int sum = 0;
    while (x >= 1) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getSum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, k;
    cin >> n;
    string op;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "Push") {
            cin >> k;
            s.push(k);
            add(k, 1);
        } else if (op == "Pop") {
            if (s.empty())
                printf("Invalid\n");
            else {
                add(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            }
        } else {
            if (s.empty())
                printf("Invalid\n");
            else
                PeekMedian();
        }
    }
    return 0;
}