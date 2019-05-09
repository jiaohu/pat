#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<set>
using namespace std;

struct node
{
	int a;
	int b;
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<node> v(m + 1);
	v.clear();
	set<int> color;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &v[i].a, &v[i].b);
	}
	int k;
	scanf("%d", &k);
	int temp[10010];
	bool flag;
	for (int i = 1; i <= k; i++) {
		flag = true;
		color.clear();
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp[i]);
			color.insert(temp[i]);
		}
		for (int i = 1; i <= m; i++) {
			if (temp[v[i].a] == temp[v[i].b]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("%lu-coloring\n", color.size());
		} else {
			printf("No\n");
		}
	}
	return 0;
}