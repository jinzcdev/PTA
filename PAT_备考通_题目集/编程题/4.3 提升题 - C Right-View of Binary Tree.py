# https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526205648747163648
def create_bt(in_order, post_order, idx, depth=0):
    global max_depth
    if len(post_order) == 0 or len(in_order) == 0:
        return
    root = post_order[-1]
    max_depth = max(depth, max_depth)
    val2idx[root] = idx
    if ans[depth] == 0 or idx > val2idx.get(ans[depth], 0):
        ans[depth] = root
    pos = in_order.index(root)
    create_bt(in_order[:pos], post_order[:pos], idx * 2, depth + 1)
    create_bt(in_order[pos+1:], post_order[pos:-1], idx * 2 + 1, depth + 1)


n = int(input())
ans = [0] * n
max_depth = -1
val2idx = dict()

in_order, post_order = list(map(int, input().split())), list(
    map(int, input().split()))
create_bt(in_order, post_order, 1, 0)
print(*ans[:max_depth+1])

"""c++
#include <bits/stdc++.h>
using namespace std;
vector<int> inorder, postorder, ans;
unordered_map<int, int> val2idx;
int n, max_depth = -1;
void create_bt(int inl, int inr, int postl, int postr, int idx, int depth) {
    if (postl > postr || inl > inr) return;
    int root = postorder[postr];
    max_depth = max(depth, max_depth);
    val2idx[root] = idx;
    if (ans[depth] == 0 || idx > val2idx[ans[depth]]) ans[depth] = root;
    int pos = inl;
    while (inorder[pos] != root) pos++;
    int numleft = pos - inl;
    create_bt(inl, inl + numleft - 1, postl, postl + numleft - 1, idx * 2, depth + 1);
    create_bt(inl + numleft + 1, inr, postl + numleft, postr - 1, idx * 2 + 1, depth + 1);
}
int main() {
    scanf("%d", &n);
    inorder.resize(n), postorder.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    ans.resize(n);
    create_bt(0, n - 1, 0, n - 1, 1, 0);
    for (int i = 0; i <= max_depth; i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
"""

""" @pintia note=start
解析: 首先理解题目含义, `right-view` 指的是二叉树中每一层最右边的结点

1. 方法一:
   - 根据 inorder, postorder 创建二叉树
   - 用层序遍历输出记录最右侧的结点
2. 方法二：
   - 在建树时, 直接记录每一层最右侧的结点
   - 用 depth 记录当前的深度, 为了知道结点在所在层是不是更靠右, 这里用了完全二叉树建树的方式, 用 `idx * 2`, `idx * 2 + 1` 表示孩子结点的序号
@pintia note=end """