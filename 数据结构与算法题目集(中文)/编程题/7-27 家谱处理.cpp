// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=842
#include <bits/stdc++.h>
using namespace std;
struct node {
    string val;
    vector<node*> link;
    node(string _val) : val(_val){};
};
vector<string> v;
unordered_map<string, string> father;

string stripl(string s) {
    while (s.length() > 0 && s[0] == ' ') s.erase(s.begin());
    return s;
}
bool is_ancestor(string acs, string child) {
    if (child == "") return false;
    if (father[child] == acs) return true;
    return is_ancestor(acs, father[child]);
}
node* create(int left, int right) {
    if (left > right) return NULL;
    if (left == right) return new node(stripl(v[left]));
    node* root = new node(stripl(v[left]));
    int first = v[left + 1].find_first_not_of(' '), pre = left + 1;
    vector<int> idx;
    for (int i = left + 2; i <= right; i++)
        if (v[i].find_first_not_of(' ') == first) idx.push_back(i);
    for (int i = 0; i < idx.size(); i++) {
        root->link.push_back(create(pre, idx[i] - 1));
        pre = idx[i];
    }
    root->link.push_back(create(pre, right));
    for (auto it : root->link) father[it->val] = root->val;
    return root;
}
int main() {
    int n, m;
    string s;
    scanf("%d%d", &n, &m);
    v.resize(n);
    getchar();
    for (int i = 0; i < n; i++) getline(cin, v[i]);
    node* root = create(0, n - 1);
    while (m--) {
        getline(cin, s);
        string a = s.substr(0, s.find_first_of(' '));
        string b = s.substr(s.find_last_of(' ') + 1);
        bool flag = false;
        if (s.find("chi") != string::npos && father[a] == b) flag = true;
        else if (s.find("anc") != string::npos && is_ancestor(a, b)) flag = true;
        else if (s.find("sib") != string::npos && father[a] == father[b]) flag = true;
        else if (s.find("par") != string::npos && father[b] == a) flag = true;
        else if (s.find("des") != string::npos && is_ancestor(b, a)) flag = true;
        printf("%s\n", flag ? "True" : "False");
    }
    return 0;
}