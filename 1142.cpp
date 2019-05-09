#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int nv, ne;
	scanf("%d%d", &nv, &ne);
	unordered_map<int, set<int> > v;
	vector<int> testque;
	set<int> exist;
	int first, second;
	for (int i = 1; i <= ne; i++) {
		scanf("%d%d", &first, &second);
		v[first].insert(second);
		v[first].insert(first);
		v[second].insert(first);
		v[second].insert(second);
	}
	int m;
	scanf("%d", &m);
	int k;
	int a[300];
	int flag;
	int isMax;
	while (m--) {
		scanf("%d", &k);
		flag = 1;
		isMax = 1;
		testque.clear();
		exist.clear();
		memset(a, 0, sizeof(a));
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
			testque.push_back(a[i]);
		}
		for (int i = 0; i < testque.size(); i++) {
			for (int j = i + 1; j < testque.size(); j++) {
				if (v[testque[i]].count(testque[j]) == 0) {
					flag = 0;
				}
			}
		}
		
		vector<int> sss;
		for (int i = 1; i <= nv; i++) {
			bool tempFlag = true;
			for (int j = 0; j < testque.size(); j++) {
				if (i == testque[j]) {
					tempFlag = false;
					break;
				}
			}
			if (tempFlag) {
				sss.push_back(i);
			}
		}
		for (int i = 0; i < sss.size(); i++) {
			bool tempFlag = true;
			for (int j = 0; j < testque.size(); j++) {
				if (v[sss[i]].count(testque[j]) == 0) {
					tempFlag = false;
					break;
				}
			}
			if (tempFlag) {
				isMax = 0;
			}
		}
		printf("%s\n",flag ? (isMax ? "Yes" : "Not Maximal") :"Not a Clique");
	}
	return 0;
}