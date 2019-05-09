#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<set>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

unordered_map<string, int> p1;
unordered_map<string, int> n1;
unordered_map<string, int> m1;
set<string> id;

struct student {
	string id;
	int p, m, n, g;
};

vector<student> v;

bool cmp(student a, student b) {
	if (a.g == b.g) {
		return a.id < b.id;
	}
	return a.g > b.g;
}

int main(int argc, char const *argv[])
{
	id.clear();
	p1.clear();
	n1.clear();
	m1.clear();
	v.clear();
	int p, n, m;
	scanf("%d%d%d", &p, &m, &n);
	string str;
	int score;
	for (int i = 1; i <= p; i++) {
		cin>>str>>score;
		p1[str] = score;
		id.insert(str);
	}
	for (int i = 1; i <= m; i++) {
		cin>>str>>score;
		m1[str] = score;
		id.insert(str);
	}
	for (int i = 1; i <= n; i++) {
		cin>>str>>score;
		n1[str] = score;
		id.insert(str);
	}
	set<string>::iterator it = id.begin();
	struct student st;
	for (; it != id.end(); it++) {
		st.id = *it;
		if (p1.find(*it) == p1.end()) {
			st.p = -1;
		} else {
			st.p = p1[*it];
		}
		if (m1.find(*it) == m1.end()) {
			st.m = -1;
		} else {
			st.m = m1[*it];
		}
		if (n1.find(*it) == n1.end()) {
			st.n = -1;
		} else {
			st.n = n1[*it];
		}
		if (st.m > st.n) {
			st.g = (int)((double)st.m * 0.4 + (double)st.n * 0.6 + 0.5);
		} else {
			st.g = st.n;
		}
		v.push_back(st);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].p >= 200 && v[i].g >= 60 && v[i].g <= 100) {
			printf("%s %d %d %d %d\n", v[i].id.c_str(), v[i].p, v[i].m, v[i].n, v[i].g);
		}
	}
	/* code */
	return 0;
}