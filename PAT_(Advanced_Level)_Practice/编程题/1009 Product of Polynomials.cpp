// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805509540921344
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, double> > p;
    int n, e, cnt = 0;
    double c, ans[2010] = {0};
    cin >> n;
    while (n--) {
        scanf("%d%lf", &e, &c);
        p.push_back({e, c});
    }
    cin >> n;
    while (n--) {
        scanf("%d%lf", &e, &c);
        for (const auto &it : p) ans[it.first + e] += it.second * c;
    }
    for (int i = 0; i <= 2000; i++)
        if (ans[i] != 0) cnt++;
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
        if (ans[i] != 0) printf(" %d %.1f", i, ans[i]);
    return 0;
}
/*
#include <cstdio>
const int maxn = 2010;
double p[maxn], ab[2][maxn];
int main(){
    int k, n, cnt = 0;
    double c;
    for (int i = 0; i < 2; i++){
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            scanf("%d%lf", &n, &c);
            ab[i][n] += c;
        }
    }
    for (int i = 0; i < maxn; i++){
        for (int j = 0; j < maxn; j++){
            if (ab[0][i] != 0 && ab[1][j] != 0) {
                int cc = i + j;
                p[cc] += ab[0][i] * ab[1][j];
            }
        }
    }
    for (int i = 0; i < maxn; i++){
        if (p[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = maxn - 1; i >= 0; i--){
        if (p[i] != 0) printf(" %d %.1f", i, p[i]);
    }
    return 0;
}
*/
/*
#include <cstdio>
struct Poly {
    int exp;
    double cof;
} poly[1001];

double ans[2001];
int main() {
    int n, m, number = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %lf", &poly[i].exp, &poly[i].cof);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int exp;
        double cof;
        scanf("%d %lf", &exp, &cof);
        for(int j = 0; j < n; j++) {
            ans[exp + poly[j].exp] += (cof * poly[j].cof);
        }
    }
    for(int i = 0; i <= 2000; i++) {
        if(ans[i] != 0.0) number++;
    }
    printf("%d", number);
    for(int i = 2000; i >= 0; i--) {
        if(ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}
*/