#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
set<int>diff[10005], same[10005];
int main(){
	int n, m, k;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++ i){
		string a, b;
		cin >> a >> b;
		int tempa = abs(stoi(a)), tempb = abs(stoi(b));
		if(a.length() != b.length()){
			diff[tempa].insert(tempb);
			diff[tempb].insert(tempa);
		}
		else{
			same[tempa].insert(tempb);
			same[tempb].insert(tempa);
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++ i){
		string a, b;
		cin >> a >> b;
		int tempa = abs(stoi(a)), tempb = abs(stoi(b));
		vector<pair<int, int>>ans;
		if(a.length() == b.length()){
			for(auto it = same[tempa].begin(); it != same[tempa].end(); ++ it){
				for(auto it2 = same[*it].begin(); it2 != same[*it].end(); ++ it2)
					if(*it != tempb && *it2 !=tempa && same[tempb].find(*it2) != same[tempb].end())
						ans.push_back(make_pair(*it, *it2));
			}
		}
		else{
			for(auto it = same[tempa].begin(); it != same[tempa].end(); ++ it){
				for(auto it2 = diff[*it].begin(); it2 != diff[*it].end(); ++ it2)
					if(same[tempb].find(*it2) != same[tempb].end())
						ans.push_back(make_pair(*it, *it2));
			}
		}
		printf("%d\n", ans.size());
		for(int i = 0;i < ans.size(); ++ i)
			printf("%04d %04d\n", ans[i].first, ans[i].second);
	}
}