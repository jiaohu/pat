#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool isPrime(int x) { 
	for (int i = 2; i < x/2; i++ ) {
		if (x %i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	unordered_map<string, int> mp;
	unordered_map<string, int> vt;
	string a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		mp[a] = i;
		vt[a] = 0;
	}
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		cin>>a;
		cout<<a<<": ";
		if (vt[a] == 0) {
			if (mp.find(a) == mp.end()) {
				printf("Are you kidding?\n");
			} else {
				if (mp[a] == 1) {
					printf("Mystery Award\n");
				} else if (isPrime(mp[a])) {
					printf("Minion\n");
				} else {
					printf("Chocolate\n");
				}
				vt[a] = 1;
			}
		} else {
			printf("Checked\n");
		}
	}
	return 0;
}