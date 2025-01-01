// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=814
#include <bits/stdc++.h>
using namespace std;
struct Node {
    string name, bir, M, tel, pho;
    Node(string a = "", string b = "", string c = "", string d = "",
         string e = "")
        : name(a), bir(b), M(c), tel(d), pho(e) {}
} N[15];
int main() {
    int n, k, ka;
    string a, b, c, d, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d >> e;
        N[i] = Node(a, b, c, d, e);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &ka);
        if (ka < n && ka >= 0) {
            cout << N[ka].name << " " << N[ka].tel << " " << N[ka].pho << " "
                 << N[ka].M << " " << N[ka].bir << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}