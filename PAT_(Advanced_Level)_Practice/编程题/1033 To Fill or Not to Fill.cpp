// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805458722734080
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x7FFFFFFF;
struct station {
    double dis, price;
} st[maxn];
bool cmp(station a, station b) {
    return a.dis < b.dis;
}
int main(){
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }
    st[n].price = 0;
    st[n].dis = D;
    sort(st, st + n, cmp);
    if (st[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int now = 0;
    double ans = 0.0, nowTank = 0, maxDis = Cmax * Davg;    // 加满油能行驶的最大距离
    while (now < n) {
        int i = now + 1, k = -1;
        double minPrice = INF;
        while (i <= n && st[i].dis - st[now].dis <= maxDis) {
            if (st[i].price < minPrice) {
                minPrice = st[i].price;
                k = i;
                if (minPrice < st[now].price) {
                    break;
                }
            }
            i++;
        }
        if (k == -1) break;
        double gasNowToK = (st[k].dis - st[now].dis) / Davg;
        if (minPrice < st[now].price) {
            if (nowTank < gasNowToK) {
                ans += (gasNowToK - nowTank) * st[now].price;
                nowTank = 0;
            } else {
                nowTank -= gasNowToK;
            }
        } else {
            ans += (Cmax - nowTank) * st[now].price;
            nowTank = Cmax - gasNowToK;
        }
        now = k;
    }
    if (now == n) printf("%.2f\n", ans);
    else printf("The maximum travel distance = %.2f\n", st[now].dis + maxDis);
    return 0;
}
