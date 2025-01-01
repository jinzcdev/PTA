// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805314941992960
#include <cstdio>
int main() {
    int num = 0;
    char ans[90][90];
    while (scanf("%s", ans[num]) != EOF) num++;
    for (int i = num - 1; i >= 0; i--) {
        printf("%s", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}

/*
#include <cstdio>
#include <cstring>
const int maxn = 90;
int main() {
    char str[90], ans[90][90];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str), num = 0, index = 0;
    for (int i = 0; i < len - 1; i++) {
        if (str[i] != ' ') {
            ans[num][index++] = str[i];
        } else {
            ans[num][index] = '\0';
            index = 0;
            num++;
        }
    }
    for (int i = num; i >= 0; i--) {
        printf("%s", ans[i]);
        if (i > 0) printf(" ");
    }
    return 0;
}
*/

/*
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new
InputStreamReader(System.in)); String str = in.readLine(); in.close(); String[]
strArr = str.split(" "); for (int i = strArr.length - 1; i >= 0; i--) {
            System.out.print(strArr[i]);
            if (i != 0)
                System.out.print(" ");
        }
    }
}
*/
