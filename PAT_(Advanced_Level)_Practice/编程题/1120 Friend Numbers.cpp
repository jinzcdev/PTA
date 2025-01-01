// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805352925609984
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40;
bool existed[maxn] = {false};
vector<int> ans;

bool cmp(int a, int b){
    return a < b;
}

int getSum(int x){
    int sum = 0;
    while (x != 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    int n, x, temp, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        temp = getSum(x);
        if (!existed[temp]){
            ans.push_back(temp);
            existed[temp] = true;
            cnt++;
        }
    }
    sort(ans.begin(), ans.begin() + cnt, cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++){
        printf("%d", ans[i]);
        if (i < cnt - 1) printf(" ");
    }
    return 0;
}