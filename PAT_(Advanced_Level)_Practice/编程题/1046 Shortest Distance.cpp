// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805435700199424
#include <iostream>
using namespace std;
const int N = 100010;
int main(){
    int n, m, left, right, temp, d[N] = {0}, sumD = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &temp);
        sumD += temp;   // sumD保存总距离
        d[i] = sumD;    // 为避免超时, 使d[i]表示1至i+1的距离
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &left, &right);
        if (left > right) swap(left, right);  // 确保前者位序小于后者
        int dist = d[right - 1] - d[left - 1];
        printf("%d\n", min(dist, sumD - dist)); // 出口构成环,两端均可达,取更短距离
    }
    return 0;
}