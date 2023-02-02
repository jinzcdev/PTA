// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805453203030016
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, grade, MIN = 999, MAX = -1;
    string name, gender, id;
    pair<string, string> m, f;
    cin >> n;
    while (n--) {
        cin >> name >> gender >> id >> grade;
        if (gender == "M" && grade < MIN) {
                MIN = grade;
                m = {name, id};
        } else if (gender == "F" && grade > MAX) {
            MAX = grade;
            f = {name, id};
        }
    }
    if (MAX != -1) cout << f.first << " " << f.second << endl;
    else cout << "Absent" << endl;
    if (MIN != 999) cout << m.first << " " << m.second << endl;
    else cout << "Absent" << endl;
    if (MAX == -1 || MIN == 999) cout << "NA";
    else cout << MAX - MIN;
    return 0;
}

/*
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct student {
    char name[15], id[15];
    char gender;
    int score;
} stuM, stuF, stu;
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
*/