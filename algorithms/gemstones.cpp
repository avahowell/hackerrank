#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<string> rocks;
	for (int i = 0; i < N; ++i) 
	{
		string rock; cin >> rock;
		rocks.push_back(rock);
	}

	vector< vector<int> > a;
	for (int i = 0; i < N; ++i) {
		a.push_back(vector<int>(26, 0));
	}
	
	for (int i = 0; i < rocks.size(); ++i) 
	{
		for (int c = 0; c < rocks[i].length(); ++c) 
		{
			++a[i][abs('a' - rocks[i][c])]; 	
		}
	}

	int gems = 0;
	int flag = 0;
	for (int c = 0; c < a.size(); ++c) {
		for (int r = 0; r < N; ++r) {
			if (a[r][c] == 0) flag = 1;
			if (flag == 0) ++gems;
		}
	} 
	cout << gems << endl;
	return 0;	
}
