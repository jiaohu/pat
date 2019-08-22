#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int friendNum(int x) {
	int ans = 0;
	while(x) {
		ans += x % 10;
		x = x / 10;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	set<int> st;
	st.clear();
	int num;
	for (int i = 1; i <=n; i++) {
		scanf("%d", &num);
		st.insert(friendNum(num));
	}
	printf("%lu\n", st.size());
	set<int>::iterator it = st.begin();
	cout<<*it;
	it++;
	for (; it != st.end(); it++) {
		cout<<" "<<*it;
	}
	cout<<endl;
	return 0;
}