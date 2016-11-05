#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//����Ϊ��ÿ����2���ݾͱ�Ϊ1���˺�ÿ��������֮ǰ�������λ��1

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec(num + 1);
	    vec[0] = 0;
	    int k = 1;
	    for (int i = 1; i <= num; ++i) {
		    if (i == k)
			    k <<= 1;
		    vec[i] = vec[i - k/2] + 1;
	    }
	    return vec;
    }
};

int main()
{
	int num = 5;
	vector<int> vec = countBits(num);
	for (int i : vec)
		cout << i << ", ";
	cout << endl;
	system("pause");
	return 0;
}