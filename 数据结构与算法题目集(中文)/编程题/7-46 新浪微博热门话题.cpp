// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=893
#include <bits/stdc++.h>
using namespace std;
struct node {
    int cnt;
    string topic;
};
bool cmp(node &a, node &b) {
    return a.cnt != b.cnt ? a.cnt > b.cnt : a.topic < b.topic;
}
string parse(string s, string &temp) {
    string ans, it;
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) it += s[i];
        if (!isalnum(s[i]) || i == s.length() - 1) {
            if (it != "") {
                for (int j = 0; j < it.length(); j++) {
                    ans += tolower(it[j]);
                    temp += tolower(it[j]);
                }
                temp += ' ';
                it = "";
            }
        }
    }
    temp[0] = toupper(temp[0]);
    temp.erase(temp.end() - 1);
    return ans;
}
int main() {
    int n;
    string s;
    scanf("%d", &n);
    unordered_map<string, int> cnt;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        unordered_map<string, bool> exist;
        bool flag = false;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (flag) {
                    string topic = s.substr(start, i - start), temp;
                    string tempTopic = parse(topic, temp);
                    // cout << "1.  " << tempTopic << endl;
                    if (!exist[tempTopic]) {
                        exist[tempTopic] = true;
                        cnt[temp]++;
                    }
                    flag = false;
                    continue;
                }
                start = i + 1;
                flag = true;
            }
        }
    }
    vector<node> ans;
    for (auto it : cnt) {
        ans.push_back({it.second, it.first});
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%s\n%d\n", ans[0].topic.c_str(), ans[0].cnt);
    int k = 0;
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i].cnt != ans[0].cnt) break;
        k++;
    }
    if (k != 0) printf("And %d more ...", k);
    return 0;
}