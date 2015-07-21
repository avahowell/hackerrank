#include <iostream>
#include <vector>
#include <cmath>
#include <string>
struct mess {
	int x;
	int y;
};
using namespace std;
void next_move(int by, int bx, std::vector<std::string> grid)
{
	if (grid[by][bx] == 'd') {
		cout << "CLEAN" << endl;
		return;
	}
	std::vector<mess> messes;
	for (int y = 0; y < 5; ++y) 
	{
		for (int x = 0; x < grid[y].length(); ++x) 
		{
			if (grid[y][x] == 'd') {
				mess m;
				m.x = x;
				m.y = y;
				messes.push_back(m);
			}
		}
	}
	
	int min_dist = 100;
	mess target;
	for (int m = 0; m < messes.size(); ++m) 
	{
		int abs_distx = abs(messes[m].x - bx);
		int abs_disty = abs(messes[m].y - by);

		if (abs_distx < min_dist) {
			min_dist = abs_distx;
			target = messes[m];
		}
		if (abs_disty < min_dist) {
			min_dist = abs_disty;
			target = messes[m];
		}
	}

	int abs_targetdistx = abs(target.x - bx);
	int abs_targetdisty = abs(target.y - by);

	if (abs_targetdistx > abs_targetdisty) {
		if (abs_targetdistx == (target.x - bx)) {
			std::cout << "RIGHT" << std::endl;
			return;
		}
		std::cout << "LEFT" << std::endl;
		return;
	}
	if (abs_targetdisty == (target.y - by)) {
		std::cout << "DOWN" << std::endl;
		return;
	}
	std::cout << "UP" << std::endl;
}
int main()
{
	int pos[2];
	std::vector<std::string> grid;
	std::cin >> pos[0] >> pos[1];

	for (int i = 0; i < 5; ++i) {
		std::string s; std::cin >> s;
		grid.push_back(s);
	}
	next_move(pos[0], pos[1], grid);
	return 0;
}
