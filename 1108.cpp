#include<iostream>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

bool isLegal(string str) {
	int len = str.length();
	bool isDot = false;
	int dotIndex = 0;
	for (int i = 0; i < len; i++) {
		if (!isDot && str[i] == '.') {
			isDot = true;
			dotIndex = i;
			if (len - dotIndex - 1 > 2) {
				return false;
			}
			continue;
		}
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue;
		}
		if (isDot && i > dotIndex && str[i] == '.') {
			return false;
		}
		int temp = str[i] - '0';
		if (temp > 9 || temp < 0) {
			return false;
		}
	}
	return true;
}


double changeToNum(string str) {
	double sum = 0;
	int len = str.length();
	int flag = 1;
	queue<int> front;
	bool isDot = false;
	int dotNum = 0;
	for (int i = 0; i < len; i++) {
		if (i == 0 && str[i] == '-') {
			flag = -1 * flag;
			continue;
		}
		if (i == 0 && str[i] == '+') {
			continue;
		}
		if (str[i] == '.') {
			isDot = true;
			continue;
		}
		front.push(str[i] - '0');
		if (isDot) {
			dotNum++;
		}
	}
	while(!front.empty()) {
		int temp = front.front();
		sum = sum * 10 + temp;
		front.pop();
	}
	if (isDot) { 
		sum = sum / pow(10, dotNum);
	}
	return flag * sum;
} 

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	string str;
	double sum = 0;
	int num = 0;
	double tempNum;
	for (int i = 0; i < n; i++) {
		cin>>str;
		if (!isLegal(str)) {
			printf("ERROR: %s is not a legal number\n", str.c_str());
		} else {
			tempNum = changeToNum(str);
			if (tempNum > 1000 || tempNum < -1000) {
				printf("ERROR: %s is not a legal number\n", str.c_str());
			} else {
				num+=1;
				sum += tempNum;
			}
		}
	}
	if (num == 0) {
		printf("The average of 0 numbers is Undefined\n");
	} else if (num == 1) {
		printf("The average of 1 number is %.2lf\n", sum);
	} else {
		printf("The average of %d numbers is %.2lf\n", num, sum/num);
	}
	return 0;
}