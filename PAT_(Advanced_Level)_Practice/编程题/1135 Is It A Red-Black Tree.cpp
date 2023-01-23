// https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,a[100];

struct Node
{
    int val;
    int bBlack;
    int lBlackNum;
    int rBlackNum;
    int tBlackNum;
    Node* left;
    Node* right;
    Node()
    {
        left = right = 0;
        lBlackNum = rBlackNum = tBlackNum = 0;
    }
    void setVal(int iVal)
    {
        if(iVal > 0) bBlack = 1;
        else if(iVal < 0)bBlack = 0;
        val = abs(iVal);
    }
};

Node* CreateTree(int l,int r)
{
    if(l > r) return NULL;
    Node* nd = new Node();
    nd -> setVal(a[l]);
    int i = l+1;
    for(;i<=r;++i)
        if(abs(a[i]) > abs(a[l])) break;
    nd -> left = CreateTree(l+1,i-1);
    nd -> right = CreateTree(i,r);
    return nd;
}

void DelTree(Node **nd)
{
    if(*nd == NULL) return;
    DelTree(&(*nd)->left);
    DelTree(&(*nd)->right);
    delete *nd;
    *nd = 0;
}
bool bIsTree = true;

int lastnum = -1;
void dfs(Node* nd,int cnt)
{
    if(!bIsTree) return;
    if(nd == NULL)
    {
        if(lastnum == -1) lastnum = cnt;
        else  if(lastnum != cnt){bIsTree = false;}
        return;
    }
    if(nd->bBlack) ++cnt;
    else
    {
        if(nd->left&&!nd->left->bBlack) bIsTree = false;
        if(nd->right&&!nd->right->bBlack) bIsTree = false;
    }
    dfs(nd->left,cnt);
    dfs(nd->right,cnt);

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        Node* root = CreateTree(0,n-1);
        bIsTree = root->bBlack;
        lastnum = -1;       //初始化会忘
        dfs(root,0);
        if(bIsTree) printf("Yes\n");
        else printf("No\n");
        DelTree(&root);     //清理内存也很重要，因为很多公司会看代码，这一行代码有加分。
    }
    return 0;
}