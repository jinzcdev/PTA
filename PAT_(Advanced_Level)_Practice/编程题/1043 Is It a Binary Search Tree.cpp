// https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1010;
int pre[maxn],in[maxn],N;

typedef struct node {
	int data;
	node* lchild;
	node* rchild;
}* Node;

/*int index = 0;
bool PreOrderTraverse(Node root){
	if(root == NULL) return true;
	else{
		if(root -> data == pre[index++]){
			PreOrderTraverse(root -> rchild);
			PreOrderTraverse(root -> lchild);
		}else{
			return false;
		}
		return true;
	}
}*/

vector<int> v_pre,v_pre_mirror;
void PreOrderTraverse(Node root){
	if(root != NULL){
		v_pre.push_back(root -> data);
		PreOrderTraverse(root -> lchild);
		PreOrderTraverse(root -> rchild);	
	}
}
void PreOrderTraverseMirror(Node root){
	if(root != NULL){
		v_pre_mirror.push_back(root -> data);
		PreOrderTraverseMirror(root -> rchild);	
		PreOrderTraverseMirror(root -> lchild);
	}
}

int i = 0;
void PostOrderTraverse(Node root){
	if(root != NULL){
		PostOrderTraverse(root -> lchild);
		PostOrderTraverse(root -> rchild);
		printf("%d",root -> data);
		if(++i < N) printf(" ");
	}
}

void PostOrderTraverseMirror(Node root){
	if(root != NULL){
		PostOrderTraverseMirror(root -> rchild);
		PostOrderTraverseMirror(root -> lchild);
		printf("%d",root -> data);
		if(++i < N) printf(" ");
	}
}

Node newNode(int x){
	Node n = new node;
	n -> data = x;
	n -> lchild = n -> rchild = NULL;
	return n;
}

void insert(Node &root,int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x < root -> data){
		insert(root -> lchild,x);
	}else{
		insert(root -> rchild,x);
	}
}

Node Create(int data[],int n){
	Node root = NULL;
	for (int i = 0; i < n; i++)
		insert(root,data[i]);
	return root;
}

bool judge(vector<int> v,int arr[]){
	int s = 0;
	for (int i = 0; i < N; i++){
		if(v[i] == arr[i])
			s++;
	}
	return s == N;
}

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d",&pre[i]);
	}
	Node root = Create(pre,N);
	PreOrderTraverse(root);
	PreOrderTraverseMirror(root);
	if(judge(v_pre,pre)){
		printf("YES\n");
		PostOrderTraverse(root);
	}else if(judge(v_pre_mirror,pre)){
		printf("YES\n");
		PostOrderTraverseMirror(root);
	}else{
		printf("NO");	
	}

	return 0;
}