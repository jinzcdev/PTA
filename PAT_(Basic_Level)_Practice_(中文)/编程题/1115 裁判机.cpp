// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1621699446021115904
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
bool out[15] = {false};
unordered_map<int, bool> record;
bool is_diff(int x) {
    for (auto it : record)
        if (record.find(it.first + x) != record.end()) return true;
    return false;
}
int main() {
    cin >> a >> b;
    record[a] = record[b] = true;
    cin >> n >> m;
    vector<vector<int> > num(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> num[j][i];
    for (int i = 0; i < m; i++) {
        vector<int> to_out;
        for (int j = 0; j < n; j++) {
            if (out[j]) continue;
            int k = num[i][j];
            if (record.find(k) == record.end() && is_diff(k)) {
                record[k] = true;
            } else {
                out[j] = true;
                to_out.push_back(j);
            }
        }
        for (auto it : to_out) {
            printf("Round #%d: %d is out.\n", i + 1, it + 1);
        }
    }
    vector<int> winners;
    for (int i = 0; i < n; i++)
        if (!out[i]) winners.push_back(i + 1);
    printf("%s", winners.size() == 0 ? "No winner." : "Winner(s):");
    for (int i = 0; i < winners.size(); i++) printf(" %d", winners[i]);
    return 0;
}