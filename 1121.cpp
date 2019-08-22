#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	long int ax, bx;
	scanf("%d", &n);
	unordered_map<long int, long int> mp;
	for (int i = 1; i <= n; i++) {
		scanf("%ld%ld", &ax, &bx);
		mp[ax] = bx;
		mp[bx] = ax;
	}
	int m;
	scanf("%d", &m);
	set<long int> st;
	long int a[10010];
	unordered_map<long int, bool> visit;
	for (int i = 1; i <= m; i++) {
		scanf("%ld", &a[i]);
		st.insert(a[i]);
		visit[a[i]] = false;
	}

	for (int i = 1; i <= m; i++) {
		if (!visit[a[i]] && !visit[mp[a[i]]] && st.find(a[i]) != st.end() && st.find(mp[a[i]]) != st.end()) {
			st.erase(a[i]);
			st.erase(mp[a[i]]);
			visit[a[i]] = true;
			visit[mp[a[i]]] = true;
		}
	}
	printf("%lu\n", st.size());
	for (set<long int>::iterator it = st.begin(); it != st.end(); it++) {
		if (it == st.begin()) {
			printf("%05ld", *it);
		} else {
			printf(" %05ld", *it);
		}
	}
	return 0;
}