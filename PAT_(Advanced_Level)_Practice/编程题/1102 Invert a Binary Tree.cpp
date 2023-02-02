// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805365537882112
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