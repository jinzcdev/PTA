// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478633632938655744
#include <bits/stdc++.h>
using namespace std;
int n, x;
bool flag = false;
vector<int> v, tmp;
void dfs(int sum, int num, int i) {
    if (num == 4) {
        if (sum % x == 0) flag = true;
        return;
    }
    if (flag || i == v.size() || v.size() - i + num < 4) return;
    tmp.push_back(v[i]);
    dfs(sum + v[i], num + 1, i + 1);
    tmp.pop_back();
    dfs(sum, num, i + 1);
}
int main() {
    scanf("%d", &n);
    while (n--) {
        flag = false;
        v.clear();
        tmp.clear();
        scanf("%d", &x);
        int sqr = (int)sqrt(x);
        for (int p = 1; p <= sqr; p++) {
            if (x % p == 0) {
                v.push_back(p);
                if (x != p * p) v.push_back(x / p);
            }
        }
        if (v.size() < 4) printf("No\n");
        else {
            dfs(0, 0, 0);
            printf("%s\n", flag ? "Yes" : "No");
        }
    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> &v, int x) {
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            for (int k = j + 1; k < v.size(); k++)
                for (int l = k + 1; l < v.size(); l++)
                    if ((v[i] + v[j] + v[k] + v[l]) % x == 0) return true;
    return false;
}
int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        vector<int> v;
        int sqr = (int)sqrt(x);
        for (int p = 1; p <= sqr; p++) {
            if (x % p == 0) {
                v.push_back(p);
                if (x != p * p) v.push_back(x / p);
            }
        }
        if (v.size() < 4) printf("No\n");
        else printf("%s\n", solve(v, x) ? "Yes" : "No");
    }
    return 0;
}
*/