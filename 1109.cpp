#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct Student
{
	string name;
	int height;
	bool operator < (const Student t) const {
		return height != t.height ? height < t.height : name > t.name;
	}
}students[10010];

int main(int argc, char const *argv[])
{
	int n, k;
	int row, left;
	scanf("%d%d", &n, &k);
	row = round((float)n / k);
	if ((n - k * row) > 0) {
		left = n - k *row;
	} else {
		left = 0;
	}
	for (int i = 0; i < n; i++) {
		cin>>students[i].name>>students[i].height;
	}
	sort(students, students + n);
	int count = 0;
	int num = 1;
	for (int i = n - 1; i >=0;) {
		int len;
		if (left != 0) {
			len = left + row;
		} else {
			len  = row;
		}
		num = len;
		Student temp[len+1];
		int index = round(len/2 + 1);
		temp[index] = students[i];
		i = i - 1;
		len -= 1;
		bool flagLeft = true;
		int leftIndex = index, rightIndex = index;
		while(len--) {
			if (flagLeft) {
				temp[leftIndex - 1] = students[i];
				leftIndex -= 1;
				flagLeft = false;
			} else {
				temp[rightIndex + 1] = students[i];
				rightIndex += 1;
				flagLeft = true;
			}
			i = i -1;
		}
		printf("%s", temp[1].name.c_str());
		for (int j = 2; j <= num; j++) {
			printf(" %s", temp[j].name.c_str());
		}
		cout<<endl;
		left = 0;
	}
	return 0;
}