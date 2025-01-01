// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805054698012672
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp (int a, int b) {
    if(abs(a) == 1000) return true;
    if(abs(b) == 1000) return false;
    return abs(a) < abs(b);
}
int main(){
    int n, m, num, k, sex[1010] = {0}, love[3];
    double sum[1010] = {0}, maxn[3] = {0} ;
    string s;
    cin >> n >> m;
    vector<vector<int>> v(m), ans(3);
    for(int i = 0; i < m; i++) {
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> s;
            if(s == "0")  s = "1000";
            if(s == "-0") s = "-1000";
            num = stoi(s);
            sex[abs(num)] = num;
            v[i].push_back(num);
        }
    }
    for(int i = 1; i <= 2; i++) {
        cin >> s;
        if(s == "0")  s = "1000";
        if(s == "-0") s = "-1000";
        love[i] = stoi(s);
    }
    for(int k = 1; k <= 2; k++) {
        for(int i = 0; i < m; i++) {
            int flag = 0;
            for(int j = 0; j < v[i].size(); j++){
                if(v[i][j] == love[k]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) {
                for(int j = 0; j < v[i].size(); j++){
                    if(love[k] * v[i][j] < 0)  {
                        sum[(int)abs(v[i][j])] += 1.0 / v[i].size();
                    }
                }
            }
        }
    }
    maxn[1] = maxn[2] = -1;
    for(int k = 1; k <= 2; k++) {
        for(int i = 1; i <= 1000; i++) {
            if(love[k] * sex[i] < 0) {
                if(sum[i] > maxn[k]) {
                    maxn[k] = sum[i];
                    ans[k].clear();
                    ans[k].push_back(sex[i]);
                }else if(sum[i] == maxn[k]) {
                    ans[k].push_back(sex[i]);
                }
            }
        }
    }
    if(maxn[1] == sum[(int)abs(love[2])] && maxn[2] == sum[(int)abs(love[1])]) {
        string s1 = to_string(love[1]), s2 = to_string(love[2]);
        if(love[1] == 1000)  s1 = "0";
        if(love[1] == -1000)  s1 = "-0";
        if(love[2] == 1000)  s2 = "0";
        if(love[2] == -1000)  s2 = "-0";
        cout << s1 << " " << s2 << endl;
        return 0;
    }
    for(int k = 1; k <= 2; k++) {
        sort(ans[k].begin(), ans[k].end(), cmp);
        for(int i = 0; i < ans[k].size(); i++) {
            string s1 = to_string(love[k]), s2 = to_string(ans[k][i]);
            if(love[k] == 1000)  s1 = "0";
            if(love[k] == -1000)  s1 = "-0";
            if(ans[k][i] == 1000)  s2 = "0";
            if(ans[k][i] == -1000)  s2 = "-0";
            cout << s1 << " " << s2 << endl;
        }
    }
    return 0;
}