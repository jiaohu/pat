#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

bool isFlag(string a, string b) {
	if (a[0] == '-' && b[0] == '-') {
		return true;
	} else if (a[0] >= '0' && a[0] <= '9' && b[0] >= '0' && b[0] <= '9') {
		return true;
	} else {
		return false;
	}
}

string resultString(string a) {
	if (a[0] == '-') {
		a.erase(a.begin());
	}
	return a;
}

bool cmpResult(pair<string,string> a, pair<string,string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first <= b.first;
}

unordered_map<string, vector<string> >mp;
vector<pair<string, string> > res;
unordered_map<string, set<string> >visit;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	mp.clear();
	res.clear();
	visit.clear();
	string a, b;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b;
		mp[a].push_back(b);
		mp[b].push_back(a);
		visit[a].insert(b);
		visit[b].insert(a);
	}
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		res.clear();
		cin>>a>>b;
		for (int j = 0; j < mp[a].size(); j++) {
			if (isFlag(a, mp[a][j]) && a != mp[a][j] && mp[a][j] != b) {
				for (int m = 0; m < mp[b].size(); m++) {
					if (isFlag(b, mp[b][m]) && b != mp[b][m] && mp[b][m] != a && visit[mp[b][m]].find(mp[a][j]) != visit[mp[b][m]].end()) {
						res.push_back(make_pair(resultString(mp[a][j]), resultString(mp[b][m])));
					}
				}
			}
		}
		printf("%lu\n", res.size());
		if (res.size() > 0) {
			sort(res.begin(), res.end(), cmpResult);
			for (int j = 0; j < res.size(); j++) {
				printf("%s %s\n", res[j].first.c_str(), res[j].second.c_str());
			}
		}
	}
	return 0;
}