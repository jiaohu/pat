#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	scanf("%d", &k);
	int n;
	int a[1010];
	bool flag;
	while(k--) {
		flag = true;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			a[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i+1; j < n; j++) {
				if (abs(i - j) == abs(a[i] -a[j]) || abs(a[i] - a[j]) == 0) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}