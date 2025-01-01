// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805361586847744
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int hobby[maxn] = {0};

bool cmp(int a, int b){
    return a > b;
}

int findFather(int x){
    if (x == father[x]) return x;
    else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB){
        father[faA] = faB;
    }
}

int main(){
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
    for (int i = 1; i <= n; i++){
        scanf("%d: ", &m);
        int h;
        for (int j = 0; j < m; j++){
            scanf("%d", &h);
            if (hobby[h] != 0){
                Union(i, hobby[h]);
            }
            hobby[h] = i;
        }
    }
    for (int i = 1; i <= n; i++){
        isRoot[findFather(i)]++;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if (isRoot[i] > 0){
            ans.push_back(isRoot[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
        if (i < ans.size() - 1) printf(" ");
    }
    return 0;
}