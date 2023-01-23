// https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, c;
    char name[5];
    scanf("%d%d", &n, &m);
    unordered_map<string, set<int> > course;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &c, &k);
        while (k--) {
            scanf("%s", name);
            course[string(name)].insert(c);
        }
    }
    while (n--) {
        scanf("%s", name);
        string sname = string(name);
        printf("%s %d", name, course[sname].size());
        for (const auto& it : course[sname]) printf(" %d", it);
        printf("\n");
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int M = 26 * 26 * 26 + 10;
set<int> course[M];
int getID(char* s) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id += (s[i] - 'A') * 26;
    }
    id += s[3] - '0';
    return id;
}
int main() {
    int n, m, k, c;
    char name[5];
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &c, &k);
        while (k--) {
            scanf("%s", name);
            course[getID(name)].insert(c);
        }
    }
    while (n--) {
        scanf("%s", name);
        int id = getID(name);
        printf("%s %d", name, course[id].size());
        for (const auto& it : course[id]) printf(" %d", it);
        printf("\n");
    }
    return 0;
}
*/