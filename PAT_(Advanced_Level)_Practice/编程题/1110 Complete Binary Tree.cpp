// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805359372255232
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 30;
bool isRoot[maxn];  // 结点是否是根结点
struct Node {
    int left, right;    // 左孩子和右孩子的下标
} node[maxn];   // 二叉树结点静态数组
// input函数输入数据
int input() {
    char id[3];
    scanf("%s", id);    // 输入结点编号
    if(id[0] == '-') {
        return -1;      // 如果是'-',说明是空结点,返回-1
    } else {
        if(strlen(id) == 1) return id[0] - '0';     // 编号小于10
        else return (id[0] - '0') * 10 + (id[1] - '0');     // 编号大于等于10
    }
}
// findRoot函数找到根结点编号
int findRoot(int n) {
    for(int i = 0; i < n; i++) {
        if(isRoot[i]) {     // isRoot为true时直接返回根结点编号i
            return i;
        }
    }
}
// BFS函数判断完全二叉树,root为根结点编号,last是最后一个结点编号(注意引用),n为结点个数
bool BFS(int root, int &last, int n) {
    queue<int> q;       // 定义队列
    q.push(root);       // 根结点入队
    while(n) {      // 只要n不为0,即还没有访问完全部非空结点
        int front = q.front();      // 队首结点front
        q.pop();        // 弹出队首结点
        if(front == -1) return false;   // 访问到空结点,一定是非完全二叉树
        n--;    // 已访问的非空结点减少1
        last = front;   // 记录最后一个非空结点编号
        q.push(node[front].left);       // 左孩子入队(包括空结点)
        q.push(node[front].right);      // 右孩子入队(包括空结点)
    }
    return true;    // 已经访问完所有非空结点,还没有碰到空结点,一定是完全二叉树
}
int main() {
    int n;
    scanf("%d", &n);    // 输入结点个数
    memset(isRoot, true, sizeof(isRoot));       //初始化所有结点都是根结点
    for(int i = 0; i < n; i++) {        // 对每一个结点
        int left = input(), right = input();    // 输入左右孩子编号
        isRoot[left] = isRoot[right] = false;   // 这两个编号一定不是根结点
        node[i].left = left;        // 记录左孩子
        node[i].right = right;      // 记录右孩子
    }
    int root = findRoot(n), last;       // 寻找根结点root,定义最后一个结点last
    bool isCompleteTree = BFS(root, last, n);      // 判断完全二叉树,同时记录最后一个结点last
    if(isCompleteTree) {        // 如果是完全二叉树
        printf("YES %d\n", last);   // 输出最后一个结点编号
    } else {
        printf("NO %d\n", root);    // 否则输出根结点编号
    }
    return 0;
}