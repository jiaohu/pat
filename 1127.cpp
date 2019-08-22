#include<iostream>
#include<vector>
using namespace std;


int inOrder[40];
int postOrder[40];
vector<vector<int> > levels(31);
void build(int root, int inl, int inr, int pl, int pr, int h) {
	if (pl > pr || inl > inr) {
		return;
	}
	root = postOrder[pr];
	levels[h].push_back(root);
	int i = 0;
	while(inOrder[inl + i] != root) {
		i++;
	}
	build(root, inl, inl + i -1, pl, pl + i - 1, h+1);
	build(root, inl + i + 1, inr, pl + i, pr - 1, h+1);
}

void zigzag()
{
    cout << levels[0][0];
    bool zigzag = false;
    for(int i = 1; i < levels.size() && !levels[i].empty();i++)
    {
        if(zigzag)
        {
            for(int j = levels[i].size() - 1;j >= 0;j--)
            {
                cout << " " << levels[i][j];
            }
        }
        else
        {
           for(int j = 0;j < levels[i].size();j++)
           {
               cout << " " << levels[i][j];
           }
        }
        zigzag = !zigzag;
    }
}


int main(int argc, char const *argv[]) {
 	int n;
 	scanf("%d", &n);
 	int root;
 	for (int i = 1; i <= n; i++) {
 		scanf("%d", &inOrder[i]);
 	}
 	for (int i = 1; i <= n; i++) {
 		scanf("%d", &postOrder[i]);
 	}
 	build(root, 1, n, 1, n, 0);
 	zigzag();
 	return 0;
 }