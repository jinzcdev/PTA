// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173571
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int START_NODE = 1002;
int n, m, k, hasCircle, in[N], in2[N], last[N];
struct node {
    int v, score, voucher;
    bool operator<(const node &x) const {
        if (score != x.score) return score > x.score;
        return voucher < x.voucher;
    }
};
struct edge {
    int next, s, d;
};
vector<edge> e[N];
queue<int> que;
vector<pair<int, int>> dis(START_NODE, {2e9, -1});
bool circle() {
    vector<int> v;
    while (que.size()) {
        int now = que.front();
        que.pop();
        v.push_back(now);
        for (auto x : e[now]) {
            in2[x.next]--;
            if (!in2[x.next]) que.push(x.next);
        }
    }
    return v.size() == n;
}
void dijkstra() {
    vector<int> vis(N);
    priority_queue<node> q;
    q.push({START_NODE, 0, 0});
    while (q.size()) {
        node now = q.top();
        q.pop();
        if (vis[now.v]) continue;
        vis[now.v] = 1;
        dis[now.v].first = now.score;
        dis[now.v].second = now.voucher;
        for (auto x : e[now.v]) {
            if (vis[x.next]) continue;
            if (dis[x.next].first > dis[now.v].first + x.s ||
                ((dis[x.next].first == dis[now.v].first + x.s) &&
                 (dis[x.next].second < dis[now.v].second + x.d))) {
                dis[x.next].first = dis[now.v].first + x.s;
                dis[x.next].second = dis[now.v].second + x.d;
                last[x.next] = now.v;
                q.push({x.next, dis[x.next].first, dis[x.next].second});
            }
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, s, d;
        scanf("%d%d%d%d", &a, &b, &s, &d);
        e[a].push_back(edge{b, s, d});
        in[b]++, in2[b]++;
    }
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            e[START_NODE].push_back({i, 0, 0});
            que.push(i);
        }
    }
    hasCircle = circle();
    dijkstra();
    cin >> k;
    if (hasCircle) cout << "Okay." << endl;
    else cout << "Impossible." << endl;
    for (int i = 0, q; i < k; i++) {
        scanf("%d", &q);
        if (!in[q]) cout << "You may take test " << q << " directly." << endl;
        else if (!hasCircle) cout << "Error." << endl;
        else {
            vector<int> path;
            while (q != START_NODE) {
                path.push_back(q);
                q = last[q];
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j];
                j &&cout << "->";
            }
            cout << '\n';
        }
    }
    return 0;
}