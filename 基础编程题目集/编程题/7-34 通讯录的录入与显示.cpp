// https://pintia.cn/problem-sets/14/problems/814
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name, date, sex, tel, phone;
};
int main() {
    int n, k, a;
    vector<node> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        node stu;
        cin >> stu.name >> stu.date >> stu.sex >> stu.tel >> stu.phone;
        v.push_back(stu);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &a);
        if (a < 0 || a >= n) cout << "Not Found" << endl;
        else {
            cout << v[a].name << " " << v[a].tel << " " << v[a].phone << " "
                 << v[a].sex << " " << v[a].date << endl;
        }
    }
    return 0;
}