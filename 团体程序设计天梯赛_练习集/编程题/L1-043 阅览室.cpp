// https://pintia.cn/problem-sets/994805046380707840/problems/994805087447138304
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char ch;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id, hh, mm, cnt = 0, sumtime = 0, sendtime[1010];
        fill(sendtime, sendtime + 1010, -1);
        while (scanf("%d %c %d:%d", &id, &ch, &hh, &mm), id != 0) {
            if (ch == 'E' && sendtime[id] != -1) {
                cnt++;
                sumtime += hh * 60 + mm - sendtime[id];
                sendtime[id] = -1;
            } else if (ch == 'S') {
                sendtime[id] = hh * 60 + mm;
            }
        }
        if (cnt == 0) printf("0 0\n");
        else printf("%d %d\n", cnt, int(round(sumtime * 1.0 / cnt)));
    }
    return 0;
}