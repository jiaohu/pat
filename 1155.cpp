#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
void run(int a[], int n, int index) {
	if (index * 2 > n && index * 2 + 1 > n) {
		if (index <= n) {
			for (int i = 0; i < v.size(); i++) {
				if (i == 0) {
					printf("%d", v[i]);
				} else {
					printf(" %d", v[i]);
				}
			}
			printf("\n");
		}
		return;
	} else {
		v.push_back(a[2 * index + 1]);
		run(a, n, 2 * index + 1);
		v.pop_back();
		v.push_back(a[2 * index]);
		run(a, n, 2 * index);
		v.pop_back();
	}
	
	// run(c, n, 2 * index - 1);
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	int a[1010];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	v.clear();
	v.push_back(a[1]);
	run(a, n, 1);
	bool isMin = true;
	bool isMax = true;
	for (int i = 2; i <= n; i++) {
		if (a[i/2] > a[i]) isMin = false;
		if (a[i/2] < a[i]) isMax = false;
	}
	if (isMin) {
		printf("Min Heap\n");
	} else if (isMax) {
		printf("Max Heap\n");
	} else {
		printf("Not Heap\n");
	}
	return 0;
}