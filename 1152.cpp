#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

bool isPrime(int index, string ch, int l, int k) {
	if (index + k - 1 > l) {
		return false;
	}
	long long int sum = 0;
	for (int i = index; i <= index + k - 1; i++) {
		sum = sum * 10 + (ch[i] - '0');
	}
	if (sum < 2) return false;
	if (sum == 2) return true;
	for (int i = 2; i * i < sum; i++) {
		if (sum % i == 0) {
			return false;
		}
	}
	return true;
}

int  main(int argc, char const *argv[])
{
	int k, l;
	scanf("%d%d", &l, &k);
	string ch;
	cin>>ch;
	for (int i = 0; i < l; i++) {
		if (isPrime(i, ch, l, k)) {
			for (int j = i; j <= i + k - 1; j++) {
				printf("%c", ch[j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("404\n");
	return 0;
}