#include<iostream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;

string reverse(string str) {
	string ans = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		ans += str[i];
	}
	return ans;
}

string add(string a, string b) {
	string ans = "";
	int cot = 0;
	stack<int> st;
	int temp;
	for (int i = a.length() - 1; i >= 0; i--) {
		temp = a[i] - '0' + b[i] - '0' + cot;
		cot = temp / 10;
		st.push(temp % 10);
	}
	if (cot != 0) {
		st.push(cot);
	}
	while(!st.empty()) {
		ans += st.top() + '0';
		st.pop();
	}
	printf("%s + %s = %s\n", a.c_str(), b.c_str(), ans.c_str());
	return ans;
}

bool isPalindromic(string s) {
	int len = s.length();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	for (int i = 1; i <= 10; i++) {
		if (isPalindromic(s)) {
			printf("%s is a palindromic number.\n", s.c_str());
			return 0;
		}
		s = add(s, reverse(s));
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}