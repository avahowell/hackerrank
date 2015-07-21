#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool can_be_palindrome(string in)
{
	string characters(in);

	vector<int> c(26);

	for (int i = 0; i < in.length(); ++i) {
		++c[in[i] - 'a'];
	}
	int odd_count = 0;
	for (int i = 0; i < 26; ++i) 
	{
		if (c[i] % 2) ++odd_count;
		if (odd_count > 1) return false;
	}
	return true;
}
int main()
{
	std::string in; cin >> in;
	if (can_be_palindrome(in)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
