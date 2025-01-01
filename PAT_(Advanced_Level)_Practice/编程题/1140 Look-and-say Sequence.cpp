// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344490864640
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int d, n;
    scanf("%d%d", &d, &n);
    int cnt;
    vector<int> ans, temp;
    temp.push_back(d);
    n--;
    while (n--) {
        cnt = 0;
        int k = temp[0];
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == k) {
                cnt++;
            } else {
                ans.push_back(temp[i - 1]);
                ans.push_back(cnt);
                k = temp[i];
                cnt = 1;
            }
            if (i == temp.size() - 1) {
                ans.push_back(temp[i]);
                ans.push_back(cnt);
            }
        }
        temp = ans;
        ans.clear();
    }
    for (auto it : temp) {
        printf("%d", it);
    }
    return 0;
}