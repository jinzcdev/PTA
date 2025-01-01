// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360043343872
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int height;
};
bool cmp(node a, node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int colnum = n / k;
    vector<node> stu(n);
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);
    int len = n % k == 0 ? colnum : colnum + n % k, id = 0;
    vector<vector<node> > group;
    for (int i = 0; i < k; i++) {
        vector<node> row(len);
        int pos = len / 2, temp = 0;
        int flag = 1;
        for (int j = 0; j < len; j++) {
            pos += temp++ * flag;
            row[pos] = stu[id++];
            flag = -flag;
        }
        group.push_back(row);
        len = colnum;
    }
    for (auto v : group) {
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) printf(" ");
            cout << v[i].name;
        }
        printf("\n");
    }
    return 0;
}