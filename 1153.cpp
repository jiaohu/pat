#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include <unordered_map>
using namespace std;

struct Card {
	string cardNum;
	string ch;
	string site;
	string date;
	string testee;
	int score;
}card[10010];

vector<Card> tempCard;

bool campType1(Card a, Card b) {
	if (a.score > b.score) {
		return true;
	} else if (a.score == b.score) {
		return a.cardNum < b.cardNum;
	} else {
		return false;
	}
}

Card convertStrToStruct(string s, Card a) {
	a.ch = s[0];
	a.site = string(s, 1, 3);
	a.date = string(s, 4, 6);
	a.testee = string(s, 10, 3);
	return a;
}

bool campType3(pair<string,int> a, pair<string,int> b) {
	if (a.second > b.second) {
		return true;
	} else if (a.second == b.second) {
		return a.first < b.first;
	} else {
		return false;
	}
}

void queryTypeOne(int n, string query) {
	tempCard.clear();
	bool flag = false;
	for(int j = 1; j <= n; j++){
		if(query == card[j].ch)
			tempCard.push_back(card[j]);
	}
	if (tempCard.size() == 0) {
		printf("NA\n");
		return;
	}
	sort(tempCard.begin(), tempCard.end(), campType1);
	for (int i = 0; i < tempCard.size(); i++) {
		printf("%s %d\n", tempCard[i].cardNum.c_str(), tempCard[i].score);
	}
	return;
}
set<string> str;
void qureyTypeTwo(int n, string query) {
	int count = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (card[i].site == query) {
			count++;
			sum += card[i].score;
		}
	}
	if (count == 0) {
		printf("NA\n");
	} else {
		printf("%d %d\n", count, sum);
	}
	return;
}
set<string> st;
unordered_map<string, int> mp;
void queryTypeThree(int n, string query) {
	st.clear();
	mp.clear();
	for (int i = 1; i <= n; i++) {
		if (card[i].date == query) {
			mp[card[i].site] += 1;
		}
	}
	if (mp.size() == 0) {
		printf("NA\n");
	} else {
		vector<pair<string, int> > ve(mp.begin(), mp.end());
		sort(ve.begin(), ve.end(), campType3);
		for (int i = 0; i < ve.size(); i++) {
			printf("%s %d\n", ve[i].first.c_str(), ve[i].second);
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n, m;
	string str[10010];
	int score[10010];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin>>str[i]>>score[i];
	}
	for (int i = 1; i <= n; i++) {
		card[i] = convertStrToStruct(str[i], card[i]);
		card[i].score = score[i];
		card[i].cardNum = str[i];
	}
	int type;
	string query;
	for (int i = 1; i <= m; i++) {
		cin>>type>>query;
		printf("Case %d: %d %s\n", i, type, query.c_str());
		if (type == 1) {
			queryTypeOne(n, query);
		} else if (type == 2) {
			qureyTypeTwo(n, query);
		} else if (type == 3) {
			queryTypeThree(n, query);
		}
	}
	return 0;
}
