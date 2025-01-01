// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805474338127872
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
  char id[15];
  int score;
  int location_number;
  int local_rank;
}stu[30010];

bool cmp(Student s1,Student s2){
    if(s1.score != s2.score) return s1.score > s2.score;
    else return strcmp(s1.id,s2.id) < 0;
}
int main(){
    int n,num = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n;i++){
        int snum;
        scanf("%d",&snum);
        for(int j = 0; j < snum;j++){
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].location_number = i;
            num++;
        }
        sort(stu + num - snum,stu + num,cmp);
        stu[num - snum].local_rank = 1;
        for(int j = 1 + num - snum; j < num;j++){
            if(stu[j].score == stu[j - 1].score){
                stu[j].local_rank = stu[j - 1].local_rank;
            }else{
                stu[j].local_rank = j + 1 - (num - snum);
                //stu[j].local_rank = stu[j - 1].local_rank + 1;
            }
        }
    }
    sort(stu,stu + num,cmp);
    printf("%d\n",num);
    int r = 1;
    for(int i = 0; i < num;i++){
        if(i > 0 && stu[i].score != stu[i - 1].score){
            r = i + 1;
        }
        printf("%s %d %d %d\n",stu[i].id,r,stu[i].location_number,stu[i].local_rank);

    }
    return 0;
}
