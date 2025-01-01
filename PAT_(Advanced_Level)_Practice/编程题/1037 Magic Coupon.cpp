// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805451374313472
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v1, v2;

int main() {
    int n, m, temp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &temp);
        v1.push_back(temp);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &temp);
        v2.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int pos = 0, sum = 0, rs;
    int p = v1.size() - 1, q = v2.size() - 1;
    while (pos <= p && pos <= q && v1[pos] < 0 && v2[pos] < 0) {
        sum += v1[pos] * v2[pos];
        pos++;
    }
    while (pos <= p && pos <= q && v1[p] > 0 && v2[q] > 0) {
        sum += v1[p] * v2[q];
        p--;
        q--;
    }
    printf("%d", sum);
    return 0;
}