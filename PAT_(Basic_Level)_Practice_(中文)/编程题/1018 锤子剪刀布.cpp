// https://pintia.cn/problem-sets/994805260223102976/problems/994805304020025344
#include <iostream>
#include <map>
using namespace std;
bool check(char a, char b) {
    return (a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C');
}
int main() {
    int n, cntA = 0, cntB = 0, cntP = 0;
    map<char, int> ma, mb;
    scanf("%d", &n);
    char chA, chB;
    while (n--) {
        getchar();
        scanf("%c %c", &chA, &chB);
        if (chA == chB) cntP++;
        else if (check(chA, chB)) {
            cntA++;
            ma[chA]++;
        } else {
            cntB++;
            mb[chB]++;
        }
    }
    printf("%d %d %d\n", cntA, cntP, cntB);
    printf("%d %d %d\n", cntB, cntP, cntA);
    chA = chB = 'B';
    if (ma['B'] < ma['C']) chA = 'C';
    if (ma['B'] < ma['J'] && ma['C'] < ma['J']) chA = 'J';
    if (mb['B'] < mb['C']) chB = 'C';
    if (mb['B'] < mb['J'] && mb['C'] < mb['J']) chB = 'J';
    printf("%c %c", chA, chB);
    return 0;
}