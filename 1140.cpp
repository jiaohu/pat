// string 添加字符可以使用push_back();
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string run(string str) {
	int count = 0;
	string ans = "";
	char temp = str[0];
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == temp) {
			count++;
		} else {
			ans = ans + temp;
			ans.push_back(count + '0');
			count = 0;
			temp = str[i];
			i--;
		}
	}
    ans = ans + temp + (char)(count + '0');
	return ans;
}

int main(int argc, char const *argv[])
{
	/* code */
	string str;
	int n;
	cin>>str>>n;
	for (int i = 1; i < n; i++) {
		str = run(str);
	}
	cout<<str<<endl;
	return 0;
}