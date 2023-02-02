// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805447855292416
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > mp;

int main() {
    int n, k, course, m;
    string stu;
    cin >> n >> k;
    while (k--) {
        cin >> course >> m;
        for (int i = 0; i < m; i++) {
            cin >> stu;
            mp[stu].insert(course);
        }
    }
    while (n--) {
        cin >> stu;
        cout << stu << " " << mp[stu].size();
        for (auto it : mp[stu]) {
            cout << " " << it;
        }
        cout << endl;
    }
    return 0;
}