#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int l, r;
	cin >> l;
	cin >> r;

	int ret = 0;
	for (int a = l; a <= r; ++a) {
		for (int b = a; b <= r; ++b) {
			ret = max(ret, a ^ b);
		}
	}	
	cout << ret << endl;	
	return 0;
}
