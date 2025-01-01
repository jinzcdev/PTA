// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1621700097589465088
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, cnt = 0;
    scanf("%d%d", &n, &m);
    priority_queue<int, vector<int>, greater<int>> inq;
    queue<int> exq;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        exq.push(a);
    }
    while (!exq.empty()) {
        queue<int> next;
        vector<int> run;
        for (int i = 0; i < m && !exq.empty(); i++) {
            inq.push(exq.front());
            exq.pop();
        }
        int size = inq.size(), out, x;
        while (!exq.empty()) {
            if (!inq.empty()) {
                run.push_back(out = inq.top());
                inq.pop();
                size--;
            }
            x = exq.front();
            exq.pop();
            if (size >= m || x <= out) {
                next.push(x);
            } else {
                inq.push(x);
                size++;
            }
        }
        while (!inq.empty()) {
            run.push_back(inq.top());
            inq.pop();
        }
        for (int i = 0; i < run.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", run[i]);
            cnt++;
        }
        printf("\n");
        exq = next;
    }
    return 0;
}
/* 网友的解法
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    priority_queue<int, vector<int>, greater<int>> in_queue;
    vector<int> ex_queue, run;
    int index = 0, count = 0, out;
    for (; index < m; index++) in_queue.push(v[index]);
    while (count != n) {
        out = in_queue.top();
        run.push_back(out);
        in_queue.pop();
        count++;
        if (index < n) {
            if (v[index] > out) in_queue.push(v[index++]);
            else ex_queue.push_back(v[index++]);
        }
        if (in_queue.empty()) {
            for (int i = 0; i < run.size(); i++) {
                if (i != 0) printf(" ");
                printf("%d", run[i]);
            }
            printf("\n");
            run.clear();
            for (int i = 0; i < ex_queue.size(); i++)
                in_queue.push(ex_queue[i]);
            ex_queue.clear();
        }
    }
}
*/