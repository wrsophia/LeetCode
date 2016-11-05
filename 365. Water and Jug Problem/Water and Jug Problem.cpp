#include <iostream>
#include <cstdlib>
using namespace std;

/*
只要 x+y>=z 并且z能被x和y的最大公约数整除就可以
*/

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
	}
	int gcd(int x, int y) {
		return y == 0 ? x : gcd(y, x % y);
	}
};