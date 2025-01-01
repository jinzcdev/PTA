// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345078067200
#include <cstdio>
#include <vector>
using namespace std;
 
struct node{
	int data;
	node* lchild;
	node* rchild;
};

int N;
vector<int> pre,in;

// void postOrder(node* root){
// 	if(root == NULL) return;
// 	postOrder(root -> lchild);
// 	postOrder(root -> rchild);
// 	printf("%d ",root -> data);
// 	return;
// }

int postOrder(node* root){
	while(root -> lchild != NULL || root -> rchild != NULL){
		if(root -> lchild)
			root = root -> lchild;
		else
			root = root -> rchild;
	}
	return root -> data;
}
node* create(int preL,int preR,int inL,int inR){
	if(inL > inR) return NULL;
	node* root = new node;
	root -> data = pre[preL];
	int k;
	for(int i = inL;i <= inR;i++){
		if(pre[preL] == in[i]){
			k = i;
			break;
		}
	}
	int leftNum = k - inL;
	root -> lchild = create(preL + 1,preL + leftNum,inL,k - 1);
	root -> rchild = create(preL + leftNum + 1,preR,k + 1,inR);
	return root;
}

int main(){
	scanf("%d",&N);
	int temp;
	for(int i = 0;i < N;i++){
		scanf("%d",&temp);
		pre.push_back(temp);
	}
	for(int i = 0;i < N;i++){
		scanf("%d",&temp);
		in.push_back(temp);
	}
	node* root = create(0,N - 1,0,N - 1);
	printf("%d",postOrder(root));
	return 0;
}
