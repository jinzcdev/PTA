// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805380754817024
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 40;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int n, pre[maxn], in[maxn];

node* create(int preL, int preR, int inL, int inR){
    if (preL > preR)
        return NULL;
    node* root = new node;
    root -> data = pre[preL];
    int k = inL;
    while (in[k] != pre[preL]){
        k++;
    }
    int numLeft = k - inL;
    root -> lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root -> rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

int cnt = 0;
void postOrder(node* root){
    if (root == NULL)
        return;
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    printf("%d", root -> data);
    if (++cnt < n) printf(" ");
}

int main(){
    scanf("%d", &n);
    stack<int> s;
    char str[5];
    int x, preIndex = 0, postIndex = 0;
    for (int i = 0; i < n * 2; i++){
        scanf("%s", str);
        if (strcmp(str,"Push") == 0){
            scanf("%d", &x);
            pre[preIndex++] = x;
            s.push(x);
        } else {
            in[postIndex++] = s.top();
            s.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}