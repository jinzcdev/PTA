// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805270356541440
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct Question {
    int no;
    int score;
    int optionNum, rightNum;
    int ans[10];
    int worngCnt;
} ques[maxn];

bool cmp(Question a, Question b){
    if (a.worngCnt != b.worngCnt)
        return a.worngCnt > b.worngCnt;
    else
        return a.no < b.no;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    // 读入题目数据
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &ques[i].score, &ques[i].optionNum, &ques[i].rightNum);
        ques[i].no = i + 1;
        char opt;
        int cnt = 0;
        while (cnt < ques[i].rightNum){
            scanf(" %c", &opt);
            // if ((opt = getchar()) != ' '){
                ques[i].ans[opt - 'a'] = 1; // 正确答案对应索引位置元素置为1, 标记其为正确选项
                cnt++;
            // }
        }
    }
    bool flag = false;  // true: 存在同学答错题目的情况
    // 读入学生答案, 并计算分数
    for (int i = 0; i < n; i++){
        int sum = 0;
        getchar();
        // printf("rightNum = ");
        for (int j = 0; j < m; j++){
            int rightNum;
            bool fault = false;
            scanf("(%d", &rightNum);
            // printf("%d ", rightNum);
            if (rightNum != ques[j].rightNum){  // 题目正确选项与学生正确选项个数不同则为错误
                ques[j].worngCnt++; // 错误次数增加一次
                fault = true;        // 标记为true
                // printf("!= false");
            }else{                              // 如果相等, 逐个判断
                // printf("true\n");
                for (int k = 0; k < rightNum; k++){
                    char opt;
                    scanf(" %c", &opt);
                    if (ques[j].ans[opt - 'a'] == 0){   // 如果该选项值为0, 则错误
                        ques[j].worngCnt++; // 错误次数增加一次
                        fault = true;        // 标记为true
                        break;              // 提前退出循环
                    }
                }
                // scanf(")");
            }
            while (getchar() != ')');
            if (j < m - 1)
                getchar();   // 接收')'后的空格
            if (!fault){
                sum += ques[j].score;   // 正确, 总分累加
            }else{
                flag = true;            // 错误, 标记出现过答错情况
            }
        }
        printf("%d\n", sum);
    }
    if (!flag){
        printf("Too simple");
    }else{
        sort(ques, ques + m, cmp);
        printf("%d %d", ques[0].worngCnt, ques[0].no);
        for (int i = 1; i < m; i++){
            if (ques[i].worngCnt == ques[i - 1].worngCnt){
                printf(" %d", ques[i].no);
            }else{
                break;
            }
        }
    }
    return 0;
}
