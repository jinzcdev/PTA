// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805493648703488
#include<vector>
#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
vector<int> Time(24,0);
struct user {
	string id;
	int month, day, hour, min;
	bool line;  //on_line is true,off_line is false
};
bool cmp(user a,user b){
	if (a.id != b.id) return a.id < b.id;
	else {
		int asum = a.day*10000 + a.hour*100 + a.min;
		int bsum = b.day * 10000 + b.hour * 100 + b.min;
		return asum < bsum;
	}
}
pair<int,int> cal(vector<user>::iterator a, vector<user>::iterator b) {
	int money = 0;
	int time = 0;
	while (a->day < b->day || a->hour < b->hour || a->min < b->min) {
		money += Time[a->hour];
		a->min++;
		time++;
		if (a->min == 60) {
			a->min = 0;
			a->hour++;
		}
		if (a->hour == 24) {
			a->hour = 0;
			a->day++;
		}
	}
	return make_pair(money ,time);
}
int main() 
{
	for (int i = 0; i < 24; i++)
		cin >> Time[i];   //input for Time ->money
	int N;
	cin >> N;
	vector<user> data(N);
	for (int i = 0; i < N; i++) {
		string input;
		cin >> data[i].id;
		scanf("%d:%d:%d:%d", &data[i].month,&data[i].day,&data[i].hour,&data[i].min);
		cin >> input;
		if (input[1] == 'n')
			data[i].line = true;
		else
			data[i].line = false;
	}
	sort(data.begin(), data.end(), cmp);
	int needprint = 0;
	auto begin = data.begin();
	for (auto it = data.begin(); it != data.end(); it++) {
		if (begin->id != it->id || it+1==data.end()) {
			if (it + 1 == data.end() && needprint == 1 && begin->id ==it->id) {
				if (it->line == false)
					needprint = 2;
				it = data.end();
			}
			if (needprint == 2){    //有一对on_line,off_line
				printf("%s %02d\n", begin->id.c_str(), begin->month);
				int total = 0.0;
				pair<int, int> money;
				auto first = data.end();
				while (begin != it ) {    //  [begin,it)    
					if (begin->line == true)
						first = begin;
					if (begin->line == false && first != data.end()) {
						printf("%02d:%02d:%02d ", first->day, first->hour, first->min);
						printf("%02d:%02d:%02d ", begin->day, begin->hour, begin->min);
						money = cal(first, begin);
						printf("%d $%.2f\n", money.second,(money.first+0.0)/100);
						total += money.first;
						first = data.end();
					}
					begin++;
				}
				printf("Total amount: $%.2f\n", (total+0.0)/100);
			}
			if (begin != data.end()) {
				begin = it;       //开始新人
				needprint = it->line == true ? 1 : 0;    //开始新人  
			}
			else
				break;
		}
		else {
			if (it->line == true && needprint ==0 )
				needprint = 1;
			else if (it->line == false && needprint == 1)    //有一对on_line,off_line
				needprint = 2;
		}
	}
	return 0;
}
