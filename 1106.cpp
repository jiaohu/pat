#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int n, k;
	double p;
	double r;
	scanf("%d%lf%lf", &n, &p, &r);
	vector<vector<int> > re(n);
	vector<int> path(n, -1), leaf;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			leaf.push_back(i);
			continue;
		}
		int temp;
		for (int j = 0; j < k; j++) {
			scanf("%d", &temp);
			re[i].push_back(temp);
		}
	}
	queue<int> res;
	path[0] = 0;
	res.push(0);
	int index, v;
	while(!res.empty()) {
		index = res.front();
		res.pop();
		for (int i = 0; i < re[index].size(); i++) {
			v = re[index][i];
			if (path[v] == -1) {
				path[v] = path[index] + 1;
				res.push(v);
			}
		}
	}
	vector<int> dist;
	for (int i = 0; i < leaf.size(); i++) {
		dist.push_back(path[leaf[i]]);
	}
	sort(dist.begin(), dist.end());
	int count = 1;
	int min = dist[0];
	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] > min) {
			break;
		}
		count++;
	}
	double money = pow(1 + r / 100.0, min) * p;
	printf("%.4lf %d\n", money, count);
	return 0;
}