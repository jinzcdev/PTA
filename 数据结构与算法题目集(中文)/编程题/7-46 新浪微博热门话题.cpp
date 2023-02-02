// https://pintia.cn/problem-sets/15/exam/problems/893
#include <bits/stdc++.h>
using namespace std;
struct node {
    int cnt;
    string topic;
};
bool cmp(node &a, node &b) {
    return a.cnt != b.cnt ? a.cnt > b.cnt : a.topic < b.topic;
}
string parse(string s, string &outputTopic) {
    string ans, it;
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) it += s[i];
        if (!isalnum(s[i]) || i == s.length() - 1) {
            if (it != "") {
                for (int j = 0; j < it.length(); j++) {
                    ans += tolower(it[j]);
                    outputTopic += tolower(it[j]);
                }
                outputTopic += ' ';
                it = "";
            }
        }
    }
    outputTopic[0] = toupper(outputTopic[0]);
    outputTopic.erase(outputTopic.end() - 1);
    return ans;
}
int main() {
    int n, k = 0;
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
                    string originalTopic = s.substr(start, i - start), outputTopic;
                    string lowerTopic = parse(originalTopic, outputTopic);
                    if (!exist[lowerTopic]) {
                        exist[lowerTopic] = true;
                        cnt[outputTopic]++;
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
    for (auto it : cnt) ans.push_back({it.second, it.first});
    sort(ans.begin(), ans.end(), cmp);
    printf("%s\n%d\n", ans[0].topic.c_str(), ans[0].cnt);
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i].cnt != ans[0].cnt) break;
        k++;
    }
    if (k != 0) printf("And %d more ...", k);
    return 0;
}