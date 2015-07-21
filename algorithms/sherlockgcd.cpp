#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T; cin >> T;
	while (--T >= 0) 
	{
		vector<int> arr;
		int n; cin >> n; // required by hackerrank
		for (int i = 0; i < n; ++i) {
			int v;
			cin >> v;
			arr.push_back(v);
		}
		int sub_len = arr.size() - 1;
		int permutation_cnt = (arr.size() - 2) * arr.size();
		for (int i = sub_len; i > 1; --i)
		{
			int p1 = 0;
			int p2 = sub_len;
			for (int q = 0; q < permutation_cnt; ++q)
			{
				vector<int> v(arr.end(), arr.begin() + 3); 
				for (int a = 0; a < v.size(); ++a)
					cout << v[a];
				cout << endl;
			}
		}
	}					
	return 0;
	
}
