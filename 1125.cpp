#include<iostream>
#include<queue>
using namespace std;

int roundInt(float a) {
	return int(a + 0.5);
}

int main(int argc, char const *argv[])
{
	int n;
	priority_queue<float, vector<float>, greater<float> > que;
	scanf("%d", &n);
	int num;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		que.push(num);
	}
	float max = que.top();
	float a, b;
	float mid;
	float res = 0;
	while(!que.empty() && que.size() > 1) {
		a = que.top();
		que.pop();
		b = que.top(); 
		que.pop();
		mid = (float)(a + b) / 2.0;
		que.push(mid); 
	}
	cout<<int(que.top())<<endl;
	return 0;
}