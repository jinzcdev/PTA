// https://pintia.cn/problem-sets/15/exam/problems/895
#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
struct node {
    string name;
    int arrive, serve;
};
int main() {
    int n, m, k;
    string name;
    scanf("%d%d", &n, &m);
    map<string, int> circle;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &k);
        while (k--) {
            cin >> name;
            circle[name] = i;
        }
    }
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].arrive >> v[i].serve;
        if (v[i].serve > 60) v[i].serve = 60;
    }
    bool is_served[N] = {false};
    int total_wait = 0, endtime = 0;  // end: the end time of the last guy.
    for (int i = 0; i < n; i++) {
        if (is_served[i]) continue;
        is_served[i] = true;
        if (v[i].arrive >= endtime) endtime = v[i].arrive + v[i].serve;
        else {
            total_wait += endtime - v[i].arrive;
            endtime += v[i].serve;
        }
        cout << v[i].name << endl;
        for (int j = i + 1; j < n; j++) {
            if (v[j].arrive > endtime) break;
            if (!is_served[j] && circle[v[i].name] == circle[v[j].name]) {
                is_served[j] = true;
                cout << v[j].name << endl;
                total_wait += endtime - v[j].arrive;
                endtime += v[j].serve;
            }
        }
    }
    printf("%.1f", 1.0 * total_wait / n);
    return 0;
}