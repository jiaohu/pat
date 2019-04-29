#include<iostream>
#include<set>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	int k;
	int a, b;
	map<int, vector<int> >res;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b;
		res[a].push_back(b);
		res[b].push_back(a);
	}
	int temp;
	while (m--) {
		cin>>k;
		int flag = 0;
		map<int, int> s;
		vector<int> v;

		for (int j = 0; j < k; j++) {
			cin>>temp;
			v.push_back(temp);
			s[v[j]] = 1;
		}
		// for (int i = 0; i < k; i++) {
		// 	cout<<v[i]<<"  "<<s[v[i]]<<endl;
		// }
		for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < res[v[i]].size(); j++)
                if (s[res[v[i]][j]] == 1) flag = 1;
        printf("%s\n",flag ? "No" :"Yes");
	}
	return 0;
}