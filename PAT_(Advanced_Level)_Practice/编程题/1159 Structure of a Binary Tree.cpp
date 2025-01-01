// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635126488367104
#include <bits/stdc++.h>
using namespace std;
vector<int> post, in;
int tree[1010], pos[1010], level[1010], len = -1;
int create(int postl, int postr, int inl, int inr, int i, int depth) {
    if (postl > postr) return 0;
    len = max(len, i);
    level[post[postr]] = depth;
    tree[i] = post[postr];
    int k = inl;
    while (k <= inr && in[k] != post[postr]) k++;
    int numLeft = k - inl;
    tree[i * 2] = create(postl, postl + numLeft - 1, inl, k - 1, i * 2, depth + 1);
    tree[i * 2 + 1] = create(postl + numLeft, postr - 1, k + 1, inr, i * 2 + 1, depth + 1);
    return post[postr];
}
int main() {
    int n, m;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    create(0, n - 1, 0, n - 1, 1, 1);
    bool isfull = true;
    for (int i = 1; i <= len; i++) {
        if (tree[i] == 0) continue;
        pos[tree[i]] = i;
        if ((tree[i * 2] != 0 || tree[i * 2 + 1] != 0) &&
            (tree[i * 2] * tree[i * 2 + 1] == 0)) {
            isfull = false;
        }
    }
    scanf("%d", &m);
    getchar();
    while (m--) {
        string s;
        bool ans;
        getline(cin, s);
        if (s[0] == 'I') ans = isfull;
        else {
            int a = stoi(s.substr(0, s.find_first_of(' ')));
            if (s[s.length() - 1] == 't') ans = pos[a] == 1;
            else if (isdigit(s[s.length() - 1])) {
                int b = stoi(s.substr(s.find_last_of(' ') + 1));
                if (s.find("pa") != string::npos) ans = pos[a] == pos[b] / 2;
                else if (s.find("le") != string::npos) ans = pos[a] == pos[b] * 2;
                else ans = pos[a] == pos[b] * 2 + 1;
            } else {
                s.erase(0, s.find_first_of(' '));
                while (!isdigit(s[0])) s.erase(s.begin());
                int b = stoi(s.substr(0, s.find_first_of(' ')));
                if (s[s.length() - 1] == 's') ans = pos[a] / 2 == pos[b] / 2;
                else ans = level[a] == level[b];
            }
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}