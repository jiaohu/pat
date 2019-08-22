#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	double a[100100];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a[i]);
	}
	double sum = 0.00;
	for (int i = 1 ; i <= n; i++) {
		sum += a[i] * (n - i + 1) * i;
	}
	printf("%.2f\n", sum);
	return 0;
}