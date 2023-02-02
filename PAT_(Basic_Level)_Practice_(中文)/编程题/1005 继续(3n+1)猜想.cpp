// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805320306507776
#include<algorithm>
#include<iostream>
using namespace std;
bool visit[105]={false};
int main(){
    int n,num[105],number;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        number=num[i];
        if(visit[number]==false){
            while(number!=1){
                if(number%2==0)
                    number=number/2;
                else
                    number=(3*number+1)/2;
                if(number<100)
                    visit[number]=true;
                
            }
        }
    }
    int cnt=1;
    sort(num,num+n);
    for(int i=n-1;i>=0;i--){
        if(visit[num[i]]==false){
            if(cnt!=1)
                cout<<" ";
            cout<<num[i];
            cnt++;
        }
    }
    cout<<endl;
}