// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805404939173888
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 30;
int a[maxn];

struct node{
	int data,height;
	node *lchild,*rchild;
};

node* newNode(int data){
	node* Node = new node;
	Node -> data = data;
	Node -> height = 1;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
}

int getHeight(node* root){
	if(root == NULL) return 0;
	return root -> height;
}

int getBalanceFactor(node* root){
	return getHeight(root -> lchild) - getHeight(root -> rchild);
}

void updateHeight(node* root){
	root -> height = max(getHeight(root -> lchild),getHeight(root -> rchild)) + 1;
}

int search(node* root,int x){
	if(root == NULL) return 0;
	if(x == root -> data) return 1;
	else if(x < root -> data)
		return search(root -> lchild,x);
	else
		return search(root -> rchild,x);
}

void L(node* &root){
	node* temp = root -> rchild;
	root -> rchild = temp -> lchild;
	temp -> lchild = root;
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

void insert(node* &root,int data){
	if(root == NULL){
		root = newNode(data);
		return;
	}
	if(data < root -> data){
		insert(root -> lchild,data);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root -> lchild) == 1)
				R(root);
			else if(getBalanceFactor(root -> lchild) == -1){
				L(root -> lchild);
				R(root);
			}
		}
	}else{
		insert(root -> rchild,data);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root -> rchild) == -1)
				L(root);
			else if(getBalanceFactor(root -> rchild) == 1){
				R(root -> rchild);
				L(root);
			}
		}
	}
}

node* Create(int data[],int n){
	node* root = NULL;
	for (int i = 0; i < n; i++){
		insert(root,data[i]);
	}
	return root;
}

void pre(node* root){
	if(root == NULL) return;
	pre(root -> lchild);
	printf("%d ",root ->data );
	pre(root -> rchild);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	node* root = Create(a,n);
	printf("%d",root -> data);
	return 0;
}
