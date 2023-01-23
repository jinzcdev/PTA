// https://pintia.cn/problem-sets/12/problems/349
int set_grade( struct student *p, int n ) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char grade;
        if (p[i].score >= 85) grade = 'A';
        else if (p[i].score >= 70) grade = 'B';
        else if (p[i].score >= 60) grade = 'C';
        else {
            grade = 'D';
            cnt++;
        }
        p[i].grade = grade;
    }
    return cnt;
}