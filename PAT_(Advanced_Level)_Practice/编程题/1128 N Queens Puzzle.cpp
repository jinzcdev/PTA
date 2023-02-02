// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805348915855360
#include <bits/stdc++.h>
using namespace std;
bool ispeace(vector<int> &chess) {
    for (int i = 1; i <= chess.size(); i++) {
        for (int j = i + 1; j < chess.size(); j++) {
            if (chess[j] - chess[i] == 0 || j - i == abs(chess[j] - chess[i]))
                return false;
        }
    }
    return true;
}
int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        vector<int> chess(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &chess[i]);
        }
        printf("%s\n", ispeace(chess) ? "YES" : "NO");
    }
    return 0;
}