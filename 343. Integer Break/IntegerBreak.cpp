#include <iostream>
#include <cstdlib>
using namespace std;

//分成尽可能多的3

int integerBreak(int n)
{
	if (n < 4)
		return n - 1;
	int p = 1;
	while (n > 2) {
		n -= 3;
		p *= 3;
	}
	if (n == 2)
		p *= n;
	if (n == 1)
		p = (p / 3) * 4;
	return p;
}

int main()
{
	int num = 34;
	cout << integerBreak(num) << endl;
	system("pause");
	return 0;
}