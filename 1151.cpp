#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<int, int> inOrderMap;

bool check(int a, int b, int order[], int n) {
	bool isA = false;
	bool isB = false;
	for (int i = 1; i <= n; i++) {
		if (order[i] == a) {
			isA = true;
		}
		if (order[i] == b) {
			isB = true;
		}
	}

	if (isA && !isB) {
		printf("ERROR: %d is not found.\n", b);
		return false;
	} else if (!isA && isB) {
		printf("ERROR: %d is not found.\n", a);
		return false;
	} else if (!isA && !isB) {
		printf("ERROR: %d and %d are not found.\n", a, b);
		return false;
	} else {
		return true;
	}
}

int min(int a, int b) {
	return a > b ? b : a;
} 

int max(int a, int b) {
	return a > b ? a : b;
}

void LCA(int a, int b, int inOrder[], int preOrder[], int n) {
	int inOrderAIndex, inOrderBIndex, preOrderAIndex, preOrderBIndex;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (inOrder[i] == a) {
			inOrderAIndex = i;
		}
		if (inOrder[i] == b) {
			inOrderBIndex = i;
		}
		if (preOrder[i] == a) {
			preOrderAIndex = i;
		}
		if (preOrder[i] == b) {
			preOrderBIndex = i;
		}
	}
	inOrderMap.clear();
	for (int i = min(inOrderAIndex, inOrderBIndex); i <= max(inOrderAIndex, inOrderBIndex); i++) {
		inOrderMap[inOrder[i]] = 1;
	}
	for (int j = 1; j <= min(preOrderAIndex, preOrderBIndex); j++) {
		if (inOrderMap[preOrder[j]] == 1) {
			ans = preOrder[j];
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

int main(int argc, char const *argv[])
{
	int m, n;
	int inOrder[10010];
	int preOrder[10010];
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inOrder[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &preOrder[i]);
	}
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if (check(a, b, inOrder, n)) {
			LCA(a, b, inOrder, preOrder, n);
		}
	}
	return 0;
}