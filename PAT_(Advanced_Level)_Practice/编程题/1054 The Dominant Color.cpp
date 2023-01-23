// https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768
#include <cstdio>
#include <map>
using namespace std;
int hashTable[16777216] = {0};
int main(){
    int m, n, k, maxCnt = 0, ans;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &k);
            if (++hashTable[k] > maxCnt) {
                maxCnt = hashTable[k];
                ans = k;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
