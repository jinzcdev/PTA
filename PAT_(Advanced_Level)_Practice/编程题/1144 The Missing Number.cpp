// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343463260160
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5+10;
const ll INF = 0x3f3f3f3f;
const double eps=1e-4;
const int T=3;
 
int a[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int pos=lower_bound(a,a+n,1)-a;
    // printf("A %d\n",a[pos]);
    if(pos>=n)
        printf("1");
    else {
        bool flag=0;
        for(int i=pos,j=1; i<n; i++,j++) {
            if(i>=1&&a[i]==a[i-1]) {
                j--;
                continue;
            }
            if(a[i]!=j) {
                printf("%d",j);
                flag=1;
                break;
            }
 
        }
        if(!flag) {
            printf("%d",a[n-1]+1);
        }
    }
    return 0;
}