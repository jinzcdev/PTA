// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805456881434624
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2010;
struct Ga{
    string head;
    int numMember;
    int total;
} Gang[maxn];
int G[maxn][maxn], w[maxn] = {0};
bool visited[maxn] = {false};
map<string, int> stringToInt;
map<int, string> intToString;
int n, k;
int numGang = 0, numPerson = 0;

bool cmp(Ga a, Ga b){
    return a.head < b.head;
}

void DFS(int begin, int &head, int &numMember, int &totalWeight){
    visited[begin] = true;
    // cout << begin << " " ;
    numMember++;
    if (w[begin] > w[head]){
        head = begin;
    }
    for (int i = 0; i < numPerson; i++){
        if (G[begin][i] > 0){
            // totalWeight += w[i];     // XXX : 加边的权值而不是顶点的权值
            totalWeight += G[begin][i];
            G[begin][i] = G[i][begin] = 0;
            if (!visited[i])
            DFS(i, head, numMember, totalWeight);
        }
    }
}

void DFSTraverse(){            // 矩阵的长度
    // int len = 0;
    for (int v = 0; v < numPerson; v++){
        if (!visited[v]){
            int head = v, numMember = 0, totalWeight = 0;
            // cout << len++ << ": ";
            DFS(v, head, numMember, totalWeight);
            if (numMember > 2 && totalWeight > k){
                Gang[numGang].head = intToString[head];
                Gang[numGang].numMember = numMember;
                Gang[numGang].total = totalWeight;
                numGang++;
            }
            // cout << "mem: " << numMember << "  total: " << totalWeight <<endl;
        }
    }
}

int change(string str){
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main(){
    cin >> n >> k;
    string name1, name2;
    int time;
    for (int i = 0; i < n; i++){
        cin >> name1 >> name2 >> time;
        int id1 = change(name1);
        int id2 = change(name2);
        w[id1] += time;
        w[id2] += time;
        G[id1][id2] += time;
        G[id2][id1] += time;
    }
    DFSTraverse();
    sort(Gang, Gang + numGang, cmp);
    // cout << G[5][6] <<"  "<<G[6][7]<<"  "<<G[7][5] <<endl;
    cout << numGang << endl;
    for (int i = 0; i < numGang; i++){
        cout << Gang[i].head << " " << Gang[i].numMember << endl;//" " << Gang[i].total << endl;
    }
    return 0;
}