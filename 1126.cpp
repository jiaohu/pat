#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[550];
int sum = 0;
bool visit[505];
bool isEven(int x) {
	return x % 2 == 0 ? true : false;
}
void dfs(int index){
    if(visit[index] == true)
        return;
    visit[index] = true;
    ++ sum;
    for(int i = 0; i < graph[index].size(); ++i)
        dfs(graph[index][i]);
}
int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	int a, b;
	int degree[550];
	int even = 0, odd = 0;
	for (int i = 1; i <=n; i++) {
		degree[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		degree[a]++;
		degree[b]++;
		graph[a].push_back(b);
        graph[b].push_back(a);
	}
	dfs(1);
	printf("%d", degree[1]);
	if (isEven(degree[1])) {
		even++;
	} else {
		odd++;
	}
	for (int i = 2; i <= n; i++) {
		if (isEven(degree[i])) {
			even++;
		} else {
			odd++;
		}
		printf(" %d", degree[i]);
	}
	printf("\n");
	if (sum == n && odd == 0) {
		printf("Eulerian\n");
	} else if (sum == n && odd == 2) {
		printf("Semi-Eulerian\n");
	} else {
		printf("Non-Eulerian\n");
	}
	return 0;
}