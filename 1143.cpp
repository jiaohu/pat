#include<iostream>
using namespace std;

bool isExist(int a, int b, int array[], int n) {
	bool flagA = false;
	bool flagB = false;
	for (int i = 0; i <n ; i++) {
		if (array[i] == a) {
			flagA = true;
		}
		if (array[i] == b) {
			flagB = true;
		}
	}

	if (!flagA && !flagB) {
		printf("ERROR: %d and %d are not found.\n", a, b);
		return false;
	} else if (flagA && !flagB) {
		printf("ERROR: %d is not found.\n", b);
		return false;
	}else if (!flagA && flagB) {
		printf("ERROR: %d is not found.\n", a);
		return false;
	}

	return true;
}

void LCA(int a, int b, int array[], int n) {
	int ans = 0;
	int indexA = 0;
	int indexB = 0;
	int minIndex = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] == a) {
			indexA = i;
		}
		if (array[i] == b) {
			indexB = i;
		}
	}
	minIndex = indexA > indexB ? indexB : indexA;
	for (int i = 0; i <= minIndex; i++) {
		if ((array[i] >= a && array[i] <= b) || (array[i] <= a && array[i] >= b)){
			ans = array[i];
			break;
		}
	}
	if (ans != a && ans != b) {
		printf("LCA of %d and %d is %d.\n", a, b, ans);
	} else if (ans == a) {
		printf("%d is an ancestor of %d.\n", a, b);
	} else if (ans == b) {
		printf("%d is an ancestor of %d.\n", b, a);
	}
	return;
}

int main() {
	int m, n;
	cin>>m>>n;
	int a[10010];
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int k, j;
	for (int i = 1; i <= m; i++) {
		cin>>k>>j;
		if (isExist(k, j, a, n)) {
			LCA(k, j, a, n);
		}
	}
	return 0;
}
