// https://pintia.cn/problem-sets/434/exam/problems/6516
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct client {
    int in, cost, vip, served;
};
struct window {
    int end, vip, cntServed;
};
int waitTime = 0, maxWait = 0, sumWait = 0;
void serve(window &win, client &c) {
    c.served = 1;
    if (win.end <= c.in) {
        win.end = c.in + c.cost;
    } else {
        maxWait = max(maxWait, win.end - c.in);
        sumWait += win.end - c.in;
        win.end += c.cost;
    }
    win.cntServed++;
}
int main() {
    int n, k, vipWin, cntServed = 0;
    cin >> n;
    vector<client> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].in >> v[i].cost >> v[i].vip;
        if (v[i].cost > 60) v[i].cost = 60;
    }
    cin >> k >> vipWin;
    vector<window> wins(k);
    wins[vipWin].vip = 1;
    for (int i = 0; i < n;) {
        if (v[i].served) {
            i++;
            continue;
        }
        int winNo = 0, MIN = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (wins[i].end < MIN) {
                MIN = wins[i].end;
                winNo = i;
            }
        }
        int vipWinNo = -1, vipCliNo = -1;
        if (v[i].in <= wins[winNo].end) {
            for (int j = 0; j < k; j++) {
                if (wins[j].end == wins[winNo].end && wins[j].vip) {
                    vipWinNo = j;
                    break;
                }
            }
            for (int j = i; j < n && v[j].in <= wins[winNo].end; j++) {
                if (!v[j].served && v[j].vip) {
                    vipCliNo = j;
                    break;
                }
            }
            if (vipWinNo != -1 && vipCliNo != -1) serve(wins[vipWinNo], v[vipCliNo]);
            else serve(wins[winNo], v[i]);
        } else {
            for (int j = k - 1; j >= 0; j--) {
                if (wins[j].end <= v[i].in) {
                    winNo = j;
                    if (wins[j].vip) vipWinNo = j;
                }
            }
            for (int j = i; j < n && v[i].in == v[j].in; j++) {
                if (v[j].vip) {
                    vipCliNo = j;
                    break;
                }
            }
            if (vipWinNo != -1 && vipCliNo != -1) serve(wins[vipWinNo], v[vipCliNo]);
            else serve(wins[winNo], v[i]);
        }
    }
    int latest = 0;
    for (int i = 0; i < k; i++) latest = max(latest, wins[i].end);
    printf("%.1f %d %d\n", sumWait * 1.0 / n, maxWait, latest);
    for (int i = 0; i < k; i++) {
        if (i != 0) cout << " ";
        cout << wins[i].cntServed;
    }
    return 0;
}

/* @pintia note=start

```
freeWins[] = 最早空闲的窗口 (可能有多个窗口同时空闲)
if 队首的客户在 freeWins 空闲之前到达 (即当 freeWins 空闲的时候至少有一个用户在排队):
    if 如果有vipWin窗口空闲, 队列中也有vipCli用户: vipWin 服务 vipCli
    else 序号最小的空闲窗口 服务 队首用户

else: // 即没有用户等待, 当有用户到达时，至少一个窗口空闲
    wins[] = 在当前用户(可能有多个)到达时所有空闲的窗口
    users[] = 最早同时到达的用户
    if users中有vip用户 && wins中有vip窗口: vip窗口 服务 vip用户
    else: 序号最小的用户去序号最小的窗口
```

@pintia note=end */