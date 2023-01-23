// https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, h1, m1, s1, h2, m2, s2, intime = 999999, outime = -1;
    string idin, idout, id;
    cin >> n;
    while (n--) {
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int t1 = h1 * 3600 + m1 * 60 + s1, t2 = h2 * 3600 + m2 * 60 + s2;
        if (t1 < intime) { idin = id; intime = t1; }
        if (t2 > outime) { idout = id; outime = t2; }
    }
    cout << idin << " " << idout;
    return 0;
}

/*
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
struct P{
    char s[10],e[10],x[50];
}a[1000];
bool cmp1(P a,P b)///从小到大
{
    if(strcmp(a.s,b.s)>0) return false;
    else return true;
}
bool cmp2(P a,P b)///从大到小
{
    if(strcmp(a.e,b.e)<0) return false;
    else return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s %s %s",&a[i].x,&a[i].s,&a[i].e);
    sort(a,a+n,cmp1);
    printf("%s ",a[0].x);
    sort(a,a+n,cmp2);
    printf("%s\n",a[0].x);
    return 0;
}
*/