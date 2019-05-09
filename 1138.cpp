#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre, in;
int main(int argc, char const *argv[])
{
	
	int n;
	scanf("%d", &n);
	int temp;
	for (int j = 0; j < n; j++) {
		scanf("%d",  &temp);
		pre.push_back(temp);
	}
	for (int j = 0; j < n; j++) {
		scanf("%d",  &temp);
		in.push_back(temp);
	}
	int preL = -1, inL = 0,  inR = n;
	int cnt, i;
	while (inL < inR) {
		++preL;
		i = inL, cnt = 0;
		while (in[i] != pre[preL]) {
			i++;
			cnt++;
		}
		if (cnt) {
			inR = i;
		} else {
			inL = i + 1;
		}
	}
	printf("%d\n", pre[preL]);
	return 0;
}