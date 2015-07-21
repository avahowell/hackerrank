#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct pixel {
	int r,g,b;
};
int main()
{
	vector<pixel> image;
	string line;
	while (getline(cin, line)) {
		vector<string> vals;
		string row;
		istringstream ss(line);
		while (getline(ss, row, ' ')) {
			pixel p;
			string pval;
			int i = 0;
			istringstream ss0(row);
			while (getline(ss0, pval, ',')) {
				if (i == 0) p.r = atoi(pval.c_str());
				if (i == 1) p.g = atoi(pval.c_str());
				if (i == 2) p.b = atoi(pval.c_str());
				++i;
			}
			image.push_back(p);
		}
	}
	
	float r_a, g_a, b_a;
	r_a = 0, g_a = 0, b_a = 0;
	float npix = 24;
	vector<float> ra;
	vector<float> ga;
	vector<float> ba;
	// Naive attempt: averaging color
	for (int p = 0; p < npix; ++p) 
	{
		ra.push_back(float(image[p].r));
		ga.push_back(float(image[p].g));
		ba.push_back(float(image[p].b));
	}
	int median_r, median_g, median_b;
	nth_element(ra.begin(), ra.begin() + ra.size()/2, ra.end());
	nth_element(ga.begin(), ga.begin() + ga.size()/2, ga.end());
	nth_element(ba.begin(), ba.begin() + ba.size()/2, ba.end());

	median_r = ra[ra.size()/2];
	median_g = ga[ga.size()/2];
	median_b = ba[ba.size()/2];
	if (median_r > 127 || median_g > 127 || median_b > 127) {
		cout << "day" << endl;
		return 0;
	}
	cout << "night" <<endl;
	
	return 0;
}
