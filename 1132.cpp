#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int getNum(int s) {
	int tmp = 0;
	while(s != 0) {
		s = s / 10;
		tmp++;
	}
	return tmp;
}

void run(int s) {
	int a, b;
	int num = getNum(s);
	num = num / 2;
	// cout<<"num"<<num<<endl;
	int div = 1;
	while(num--) {
		div *= 10;
	}
	// cout<<"div"<<div<<endl;
	
	a = s / div;
	// cout<<"a"<<a<<endl;
	b = s % div;
	// cout<<"b"<<b<<endl;
	if (a * b == 0) {
		printf("No\n");
	} else if (s % (a * b) == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main(int argc, char const *argv[])
{

	/* code */
	int n;
	scanf("%d", &n);
	int s;
	while(n--) {
		scanf("%d", &s);
		run(s);
	}
	return 0;
}