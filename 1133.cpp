#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

struct Result
{
	string first, end;
	int value;
};

int main(int argc, char const *argv[])
{
	/* code */
	string first;
	int n, k;
	cin>>first>>n>>k;
	struct Result node;
	unordered_map<string,  Result> mp;
	vector<Result> v;
	vector<Result> ans;
	string a, c;
	int b;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a>>b>>c;
		node.first = a;
		node.value = b;
		node.end = c;
		mp[a] = node;
	}
	string temp = first;
	while(temp != "-1") {
		v.push_back(mp[temp]);
		temp = mp[temp].end;
	}
	
	int t = v.size();
	for (int i = 0; i < t; i++) {
		if (v[i].value < 0) {
			ans.push_back(v[i]);
		}
	}
	for (int i = 0; i < t; i++) {
		if (v[i].value >= 0 && v[i].value <= k) {
			ans.push_back(v[i]);
		}
	}
	for (int i = 0; i < t; i++) {
		if (v[i].value >= 0 && v[i].value > k) {
			ans.push_back(v[i]);
		}
	}
	for (int i = 0; i < t; i++) {
		if (i == t - 1) {
			ans[i].end = "-1";
		} else {
			ans[i].end = ans[i+1].first;
		}
		cout<<ans[i].first<<" "<<ans[i].value<<" "<<ans[i].end<<endl;
	}
	return 0;
}