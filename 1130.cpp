#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

struct node
{
	int l, r;
	string str;
}node[30];

void dfs(int x, int root) {
	if (x == -1) {
		return;
	}
	if (x != root && (node[x].l != -1 || node[x].r != -1)) {
		printf("(");
	}
	dfs(node[x].l, root);
	cout<<node[x].str;
	dfs(node[x].r, root);
	if (x != root && (node[x].l != -1 || node[x].r != -1)) {
		printf(")");
	}

}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	scanf("%d", &n);
	int vis[30];
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n; i++) {
		cin>>node[i].str>>node[i].l>>node[i].r;
		if (node[i].l != -1) {
			vis[node[i].l] = 1;
		}
		if (node[i].r != -1) {
			vis[node[i].r] = 1;
		}
	
	}
	int root = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			root = i;
			break;
		}
	}
	dfs(root, root);
	printf("\n");
	return 0;
}