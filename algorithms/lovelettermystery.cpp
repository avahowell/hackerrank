#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int make_palindrome(string in)
{
	int ops = 0;
	for (int i = 0; i < in.length()/2; ++i) 
	{
		ops += abs(in[i] - in[in.length()-i-1]);
	}
	return ops;
}
	

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string test; cin >> test;
		cout << make_palindrome(test) << endl;	
	}
		 	
	return 0;
}

