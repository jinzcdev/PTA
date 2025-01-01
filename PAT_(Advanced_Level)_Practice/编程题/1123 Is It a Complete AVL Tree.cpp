// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805351302414336
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 25;
struct node {
    int data, height;
    node *lchild, *rchild;
    node(int _data){
        data = _data;
        height = 1;
        lchild = rchild = NULL;
    }
} *root;
int n, ans[maxn];

int getHeight(node* root) {
    if(root == NULL) return 0;
    return root->height;
}

void updateHeight(node* root){
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
	node* temp = root -> lchild;
	root -> lchild = temp -> rchild;
	temp -> rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) {
        insert(root->lchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                R(root);
            } else if(getBalanceFactor(root->lchild) == -1) {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {
                L(root);
            } else if (getBalanceFactor(root->rchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

void levelOrder(node* root) {
    queue<node*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        if (++cnt < n) printf(" ");
        if (now->lchild != NULL) q.push(now->lchild);
        if (now->rchild != NULL) q.push(now->rchild);
    }
}

bool isCBT(node* root, int n){
    queue<node*> q;
    q.push(root);
    while (n--){
        node* now = q.front();
        q.pop();
        if (now == NULL) return false;
        q.push(now->lchild);
        q.push(now->rchild);
    }
    return true;
}

int main(){
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        insert(root, x);
    }
    levelOrder(root);
    if (isCBT(root, n)) printf("\nYES");
    else printf("\nNO");
    return 0;
}