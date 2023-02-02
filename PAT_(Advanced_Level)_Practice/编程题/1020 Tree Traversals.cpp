// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805485033603072
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 30;

int n,in[maxn],post[maxn];

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

Node* create(int postL,int postR,int inL,int inR){
	if(postL > postR) return NULL;
	Node* root = new Node;
	root -> data = post[postR];
	int k;
	for (k = inL; k <= inR; ++k){
		if(in[k] == post[postR])
			break;
	}
	int numLeft = k - inL;
	root -> lchild = create(postL,postL + numLeft - 1,inL,k - 1);
	root -> rchild = create(postL + numLeft,postR - 1,k + 1,inR);
	return root;
}

void BFS(Node* root){
	queue<Node *> q;
	q.push(root);
	int num = 0;
	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		printf("%d",node -> data);
		if(++num < n) printf(" ");
		if(node -> lchild != NULL) q.push(node -> lchild);
		if(node -> rchild != NULL) q.push(node -> rchild);
	}
}
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i){
		scanf("%d",&post[i]);
	}
	for (int i = 0; i < n; ++i){
		scanf("%d",&in[i]);
	}
	Node* root = create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}