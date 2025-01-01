// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805263964422144
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string stu[1005];

int main() 
{
	int N,M,K;
	int find[15],thing[15],ans[15];
	cin>>N>>M;
	for (int i=0;i<M;i++) {
		cin>>find[i];
	}
	int count1=0,count2=0;
	for (int i=0;i<N;i++) {
		cin>>stu[i];
		cin>>K;
		if (K==0) {
			continue;
		}
		int p=0,flag=0;
		for (int j=0;j<K;j++) {
			cin>>thing[j];
			for (int k=0;k<M;k++) {
				if (thing[j]==find[k]) {
					count2++;
					flag=1;
					ans[p++]=thing[j];
				}
			}
		}  
		if(flag) {
			count1++;
			cout<<stu[i]<<":";
			for (int i=0;i<p;i++) {
				printf(" %04d",ans[i] );  // 注意输出格式 是%04d
			}
			cout<<endl;
		}
	}
	cout<<count1<<" "<<count2<<endl;
	return 0;
}