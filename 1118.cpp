#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

int father[10010];

void init(){
	for (int i=0;i<10010;i++)
		father[i]=i;
}
int findFather(int x){
	int a=x;
	while (x!=father[x])
		x=father[x];
	while (a!=father[a])
	{
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb)
		father[fa]=fb;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int k, b, temp;
	set<int> birds, tree;
	init();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d", &b);
			if (j == 1) {
				temp = b;
			}
			Union(temp, b);
			birds.insert(b);
		}
	}
	set<int>::iterator it = birds.begin();
	for (;it!=birds.end();it++) {
		tree.insert(findFather((*it)));
	}
	printf("%lu %lu\n",tree.size(),birds.size());
	scanf("%d", &k);
	int a, c;
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &a, &c);
		if (findFather(a) == findFather(c)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}