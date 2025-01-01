// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038429808099098624
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> lie, isgood(n, 1);
            isgood[i] = isgood[j] = -1;
            for (int k = 0; k < n; k++)
                if (v[k] * isgood[abs(v[k]) - 1] < 0) lie.push_back(k);
            if (lie.size() == 2 && isgood[lie[0]] + isgood[lie[1]] == 0) {
                printf("%d %d", i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}