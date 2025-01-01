// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805424153280512
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;
int index = 0,s;
int path[maxn];

struct node{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a,int b){
	return Node[a].weight > Node[b].weight;
}

void sortVector(vector<int> v){
	sort(v.begin(),v.end(),cmp);
}

void DFS(int index,int nodeNum,int sum){
	if(sum > s) return;
	if(sum == s){
		if(Node[index].child.size() != 0) return;
		for(int i = 0;i < nodeNum;i++){
			printf("%d",Node[path[i]].weight);
			if(i < nodeNum - 1) printf(" ");
		}
		printf("\n");
		return;
	}
	for(int i = 0;i < Node[index].child.size();i++){
		int child = Node[index].child[i];
		path[nodeNum] = child;
		DFS(child,nodeNum + 1,sum + Node[child].weight);
	}
	
}

int main(){
	int n,m; //节点数,非leaf节点数,权值.
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 0;i < n;i++){
		scanf("%d",&Node[i].weight);
	}
	int id,k,child;
	for(int i = 0;i < m;i++){
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k;j++){
			scanf("%d",&child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);
	}
	path[0] = 0;
	DFS(0,1,Node[0].weight);

	return 0;
}