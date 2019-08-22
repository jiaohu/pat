#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

vector<int> seq;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void fill(int m, int n) {
	int a[m+1][n+1];
	int visit[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
			a[i][j] = 0;
		}
	}
	int x = 0, y = 0;
	int z = 0;
	for (int i = 0 ; i < seq.size(); i++) {
		if (x + dx[z] >= m || y + dy[z] >= n || y + dy[z] < 0 || x + dx[z] < 0 || visit[x + dx[z]][y + dy[z]] == 1) {
			z++;
			if (z == 4) {
				z = 0;
			}
		}
		a[x][y] = seq[i];
		visit[x][y] = 1;
		x += dx[z];
		y += dy[z];
	}
	for (int i = 0 ; i < m; i++) {
		printf("%d", a[i][0]);
		for (int j = 1 ;j < n; j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	seq.clear();
	int value;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &value);
		seq.push_back(value);
	}
	int m, n;
	int min = N;
	for (int i = 1; i <= N; i++)  {
		if (N % i == 0 && (abs(i - N / i) < min)) {
			m = i >= (N / i) ? i : N / i;
			n = N / m;
			min = m - n;
		}
	}
	sort(seq.begin(), seq.end(), greater<int>());
	fill(m, n);
	return 0;
}