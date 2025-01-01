# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526206272981233664
N = 1010
father = [i for i in range(10010)]
score = [0] * 10010
sid = set()


class Node:
    def __init__(self, id):
        self.id = id
        self.cnt_mate = 0
        self.total_score = 0


def find_father(x):
    if x == father[x]:
        return x
    father[x] = find_father(father[x])
    return father[x]


def uni(a, b):
    faA = find_father(a)
    faB = find_father(b)
    if faA <= faB:
        father[faB] = faA
    else:
        father[faA] = faB


n = int(input())
for i in range(n):
    id, k, *lst = map(int, input().split())
    sid.add(id)
    for t in lst[:-1]:
        sid.add(t)
        uni(id, t)
    score[id] = lst[-1]

m = {}
for it in sid:
    fa = find_father(it)
    if fa not in m:
        m[fa] = Node(id=fa)
    m[fa].cnt_mate += 1
    m[fa].total_score += score[it]

ans = list(m.values())
ans.sort(key=lambda x: (-x.total_score, x.cnt_mate, x.id))

print(len(ans))
for it in ans:
    print(f"{it.id:04d} {it.cnt_mate} {it.total_score}")

"""c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct node {
    int id, cnt = 0, sum = 0;
};
int father[10010], score[10010] = {0};
bool cmp(node &a, node &b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    return a.cnt != b.cnt ? a.cnt < b.cnt : a.id < b.id;
}
int findfather(int x) {
    return x == father[x] ? x : father[x] = findfather(father[x]);
}
void uni(int a, int b) {
    int faA = findfather(a), faB = findfather(b);
    if (faA <= faB) father[faB] = faA;
    else father[faA] = faB;
}
int main() {
    for (int i = 0; i < 10010; i++) father[i] = i;
    unordered_set<int> sid;
    int n, id, k, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &k);
        sid.insert(id);
        while (k--) {
            scanf("%d", &t);
            sid.insert(t);
            uni(id, t);
        }
        scanf("%d", &score[id]);
    }
    int cnt = 0;
    unordered_map <int, node> m;
    for (auto it : sid) {
        int fa = findfather(it);
        m[fa].id = fa;
        m[fa].cnt++;
        m[fa].sum += score[it];
    }
    vector<node> ans;
    for (auto it : m) {
        ans.push_back(it.second);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (auto it : ans) {
        printf("%04d %d %d\n", it.id, it.cnt, it.sum);
    }
    return 0;
}
"""

""" @pintia note=start
解析: 从题目描述可以判断这是一道考察并查集的题目

方法一: 
1. 用并查集合并所有出现的成员
2. 遍历所有成员, 用哈希表记录一共有多少个队伍, 队伍的人数和总分
3. 题目要求队伍 ID 用编号最小的那个成员, 因此在并查集合并的时候就让更小的那个为 father

@pintia note=end """