#include<iostream>
#include<string>
#include<cstring>
#include<unordered_map>
#include<set>
#include<cctype>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	string id;
	int score;
	string school;
}node[100010];

struct ans
{
	string ins;
	int score;
	int count;
};

bool cmp1(ans t1, ans t2) {
	if (t1.score != t2.score) {
		return t1.score > t2.score;
	} else if (t1.count != t2.count) {
		return t1.count < t2.count;
	} else {
		return t1.ins < t2.ins;
	}
}

set<string> institution;
vector<ans> result;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	institution.clear();
	unordered_map<string, unordered_map<char, int> > schoolTotalScore;
	unordered_map<string, int> testeeNum;
	for (int i = 1; i <= n; i++) {
		cin>>node[i].id>>node[i].score>>node[i].school;
		std::transform(node[i].school.begin(), node[i].school.end(), node[i].school.begin(), ::tolower);
		institution.insert(node[i].school);
	}
	int temp;
	for (int i = 1; i <= n; i++) {
		temp = 0;
		if (node[i].id[0] == 'A') {
			schoolTotalScore[node[i].school]['A'] += node[i].score;
		} else if (node[i].id[0] == 'B') {
			schoolTotalScore[node[i].school]['B'] += node[i].score;
		} else if (node[i].id[0] == 'T') {
			schoolTotalScore[node[i].school]['T'] += node[i].score;
		}
		testeeNum[node[i].school] += 1;
	}
	set<string>::iterator it = institution.begin();

	for (; it != institution.end(); it++) {
		struct ans temp;
		temp.ins = *it;
		temp.score = (int)(schoolTotalScore[*it]['A'] + (double)schoolTotalScore[*it]['B'] / 1.5 + (double)schoolTotalScore[*it]['T'] * 1.5);
		temp.count = testeeNum[*it];
		result.push_back(temp);
	}
	printf("%lu\n", institution.size());
	sort(result.begin(), result.end(), cmp1);
	int rank = 0, pres = -1;
	//printf("%d %s %d %d\n", rank, result[0].ins.c_str(), result[0].score, result[0].count);
	for (int i = 0; i < result.size(); i++) {
		if (pres != result[i].score) rank = i + 1;
        pres = result[i].score;
		printf("%d %s %d %d\n", rank, result[i].ins.c_str(), result[i].score, result[i].count);
	}
	return 0;
}