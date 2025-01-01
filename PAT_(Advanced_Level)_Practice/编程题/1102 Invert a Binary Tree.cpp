// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805365537882112
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 15;
struct {
    int data;
    int lchild, rchild;
} node[maxn];

int n, cnt = 0;
bool isChild[maxn] = {false};

void levelorder(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d", node[now].data);
        if (++cnt < n) printf(" ");
        if (node[now].rchild != -1) q.push(node[now].rchild);
        if (node[now].lchild != -1) q.push(node[now].lchild);
    }
    printf("\n");
}

void inorder(int root){
    if (root == -1)
        return;
    inorder(node[root].rchild);
    printf("%d", node[root].data);
    if (++cnt < n) printf(" ");
    inorder(node[root].lchild);
}

int main(){
    for (int i = 0; i < maxn; i++){
        node[i].data = i;
        node[i].lchild = node[i].rchild = -1;
    }
    scanf("%d", &n);
    char lchild, rchild;
    for (int i = 0; i < n; i++){
        getchar();
        scanf("%c %c", &lchild, &rchild);
        if (lchild != '-'){
            node[i].lchild = lchild - '0';
            isChild[lchild - '0'] = true;
        }
        if (rchild != '-'){
            node[i].rchild = rchild - '0';
            isChild[rchild - '0'] = true;
        }
    }
    int root = 0;
    while (isChild[root]){
        root++;
    }
    levelorder(root);
    cnt = 0;
    inorder(root);
    return 0;    
}
/* @pintia note=start
## 解题笔记

这道题目要求我们翻转一棵二叉树，并输出翻转后的层序遍历和中序遍历。

### 解题思路

1. **数据结构**：
    - 使用一个结构体数组 `node` 来存储二叉树的节点，每个节点包含数据、左孩子和右孩子。
    - 使用一个布尔数组 `isChild` 来标记节点是否是某个节点的孩子节点。

2. **输入处理**：
    - 读取节点数 `n`。
    - 读取每个节点的左右孩子信息，并更新 `node` 数组和 `isChild` 数组。

3. **找到根节点**：
    - 根节点是 `isChild` 数组中值为 `false` 的节点。

4. **翻转二叉树**：
    - 在层序遍历和中序遍历时，交换左右孩子节点的位置即可实现翻转。

5. **遍历输出**：
    - 使用队列进行层序遍历。
    - 使用递归进行中序遍历。

### 代码实现

代码中已经实现了输入处理、找到根节点、层序遍历和中序遍历的功能。我们只需要在遍历时交换左右孩子节点的位置即可实现翻转。

### 注意事项

- 输入的节点编号是字符，需要转换为整数。
- 遍历时要注意输出格式，节点之间用空格分隔，最后一个节点后不应有空格。

@pintia note=end */