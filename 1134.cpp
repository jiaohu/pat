#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int> > v;
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	int k;
	scanf("%d", &k);
	int t;
	unordered_map<int, int> mp;
	bool flag;
	while (k--) {
		scanf("%d", &t);
		mp.clear();
		flag = true;
		for (int i = 1; i <= t; i++) {
			scanf("%d", &a);
			mp[a] = 1;
		}
		for (int i = 0; i < v.size(); i++) {
			if (mp[v[i].first] == 1 || mp[v[i].second] == 1) {
				continue;
			} else {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}