#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, T;
	vector<int> road;

	cin >> N >> T;


	for (int i = 0; i < N; ++i) {
		int r; cin >> r;
		road.push_back(r);
	} 
	for (int i = 0; i < T; ++i) {
		int enter, exit; cin >> enter >> exit;
		
		int min = 3;
		for (int s = enter; s <= exit; ++s) {
			if (road[s] < min) min = road[s];
		}
		cout << min << endl;
	}
	
	return 0;
}
