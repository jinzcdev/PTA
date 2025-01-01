// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805453203030016
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
// const int maxn 
struct student {
    char name[15], id[15];
    char gender;
    int score;
} stuM, stuF, stu;
// vector<student>;
int main(){
    int n, maxF = -1, minM = 110;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s %c %s %d", stu.name, &stu.gender, stu.id, &stu.score);
        if (stu.gender == 'M' && stu.score < minM) {
            stuM = stu;
            minM = stu.score;
        } else if (stu.gender == 'F' && stu.score > maxF) {
            stuF = stu;
            maxF = stu.score;
        }
    }
    if (maxF != -1 && minM != 110) {
        printf("%s %s\n", stuF.name, stuF.id);
        printf("%s %s\n", stuM.name, stuM.id);
        printf("%d\n", stuF.score - stuM.score);
    } else if (maxF != -1) {
        printf("%s %s\n", stuF.name, stuF.id);
        printf("Absent\nNA");
    } else {
        printf("Absent\n");
        printf("%s %s\nNA", stuM.name, stuM.id);
    }
    return 0;
}