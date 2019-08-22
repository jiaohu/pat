#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int n, m, s;
	string a[1010];
	unordered_map<string, bool> visit;
	cin>>n>>m>>s;
	for (int i = 1; i <=n; i++) {
		cin>>a[i];
	}
	vector<string> ve;
	ve.clear();
	int index;
	if (s > n) {
		printf("Keep going...\n");
		return 0;
	}

	for (int i = s; i <= n; i+=m) {
		if (visit[a[i]] == false) {
			ve.push_back(a[i]);
			visit[a[i]] = true;
		} else if (visit[a[i]] == true) {
			while(i < n) {
				i++;
				if (visit[a[i]] == false) {
					visit[a[i]] = true;
					ve.push_back(a[i]);
					break;
				}
			}
		}
	}
	if (ve.size() == 0) {
		printf("Keep going...\n");
	} else {
		for (int i = 0 ; i < ve.size(); i++) {
			printf("%s\n", ve[i].c_str());
		}
	}
	return 0;
}