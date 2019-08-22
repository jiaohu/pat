#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Node
{
	int value;
	int times;
	bool operator < (const Node b) const {
		return times != b.times ? times > b.times : value < b.value;
	}
	Node(int _x, int _y) :value(_x), times(_y) {}
};

int a[50010];
int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d%d", &n, &k);
	set<Node> st;
	set<int> list;
	int num[50010];
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
		num[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i >=2) {
			printf("%d:", a[i]);
			int j = 0;
			for (set<Node>::iterator it = st.begin(); j < k && it != st.end(); j++, it++) {
				printf(" %d", it->value);
			}
			printf("\n");
		}
		set<Node>::iterator it = st.find(Node(a[i],num[a[i]]));
		if(it != st.end()) st.erase(it);
		num[a[i]]++;
		st.insert(Node(a[i], num[a[i]]));
	}
	return 0;
}
