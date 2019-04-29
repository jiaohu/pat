#include<iostream>
#include<cstdio>
#include<string>
#include<string.h>
using namespace std;

#define MAXINDEX 220
#define INF 0xffff

int dist[MAXINDEX][MAXINDEX];
int visit[MAXINDEX];

bool isNA(int i, int j) {
	if (dist[i][j] == INF) {
		return true;
	}
	return false;
}

void initDist(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
}

int run(int c[], int n, int k, bool isAllVisit) {
	int totalDist = 0;
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (c[i] == c[1]) {
			count++;
		}
		if (isNA(c[i], c[i+1])) {
			printf("Path %d: NA (Not a TS cycle)\n", k);
			return INF;
		} 
		totalDist += dist[c[i]][c[i+1]];
	}
	if (c[1] == c[n]) {
		count++;
	}
	if (isAllVisit) {
		if (count == 1) {
			printf("Path %d: %d (Not a TS cycle)\n", k, totalDist);
			return INF;
		} else if (count == 2) {
			printf("Path %d: %d (TS simple cycle)\n", k, totalDist);
		} else {
			printf("Path %d: %d (TS cycle)\n", k, totalDist);
		}
	} else {
		printf("Path %d: %d (Not a TS cycle)\n", k, totalDist);
		return INF;
	}
	return totalDist;
}

int main(int argc, char const *argv[])
{
	int n, m, k;
	scanf("%d%d", &n, &m);
	initDist(n);
	int a,b,d;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		dist[a][b] = dist[b][a] = d;
	}
	int c[MAXINDEX];
	scanf("%d", &k);
	int cn;
	int small = INF;
	int temp, index;
	bool isAllVisit;
	for (int x = 1; x <= k; x++) {
		scanf("%d", &cn);
		memset(visit, 0, sizeof(visit));
		isAllVisit = false;
		for (int i = 1; i <= cn; i++) {
			scanf("%d", &c[i]);
			visit[c[i]] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				isAllVisit = false;
				break;
			}
			if (i == n) {
				isAllVisit = true;
			}
		}
		temp = run(c, cn, x, isAllVisit);
		if (small > temp) {
			small = temp;
			index = x;
		}
	}
	printf("Shortest Dist(%d) = %d\n", index, small);
	return 0;
}