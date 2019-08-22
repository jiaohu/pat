#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int> > mp(n + 1);
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	int k;
	scanf("%d", &k);
	int t;
	int index[300];
	bool flag;
	bool temp;
	int vist[300];
	while(k--) {
		scanf("%d", &t);
		flag = true;
		for (int i = 1; i <= n; i++) {
			vist[i] = 0;
		}
		for (int i = 0; i < t; i++) {
			scanf("%d", &index[i]);
			vist[index[i]] = 1;
		}
		if (t != n + 1) {
			printf("NO\n");
			continue;
		}
		if (index[0] != index[t - 1]) {
			printf("NO\n");
			continue;
		}

		for (int i = 1; i < t; i++) {
			temp = false;
			for (int j = 0; j < mp[index[i-1]].size(); j++) {
				if (mp[index[i-1]][j] == index[i]) {
					temp = true;
					break;
				}
			}
			if (temp) {
				flag = true;
			} else {
				flag = false;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (vist[i] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}


	return 0;
}