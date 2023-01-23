// https://pintia.cn/problem-sets/994805260223102976/problems/994805266942377984
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 500010;
int main() {
    int n, m, a, b, id;
    vector<int> couple(100000, -1);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }
    cin >> m;
    vector<int> guest;
    int isExited[maxn] = {false};
    while (m--) {
        cin >> id;
        guest.push_back(id);
        isExited[id] = true;
    }
    set<int> ans;
    for (auto it : guest) {
        if (couple[it] == -1) ans.insert(it);
        else if (!isExited[couple[it]]) ans.insert(it);
    }
    printf("%d\n", ans.size());
    int cnt = 0;
    for (auto it : ans) {
        printf("%05d", it);
        if (++cnt < ans.size()) printf(" ");
    }
    return 0;
}