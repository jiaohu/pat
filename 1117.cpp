#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a[100100];
	scanf("%d", &n);
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n, greater<int>());
	int t= 0;
	while(t < n && a[t] > t + 1) {
		t++;
	}
	printf("%d\n", t);
	return 0;
}