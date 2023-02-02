// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1478634991737962496
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, cnt = 0;
    string oldestAlumni = "xxxxxx99999999", oldestGuest = "xxxxxx99999999", id;
    scanf("%d", &n);
    map<string, bool> isalumni;
    for (int i = 0; i < n; i++) {
        cin >> id;
        isalumni[id] = true;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        cin >> id;
        if (id.substr(6, 8) < oldestGuest.substr(6)) oldestGuest = id;
        if (isalumni[id]) {
            if (id.substr(6, 8) < oldestAlumni.substr(6)) oldestAlumni = id;
            cnt++;
        }
    }
    printf("%d\n%s", cnt, cnt > 0 ? oldestAlumni.c_str() : oldestGuest.c_str());
    return 0;
}