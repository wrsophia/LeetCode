/**
 * 这个有点类似进制问题，比如，n=4,k=9时，每隔3!次最高位变一次，每隔2!次第二位变一次，于是可以写为
 * 9 = 1*3! + 1*2! + 0*1! + 1，当前应放置数字(字符)在剩余数字组成的数组中的位置为系数i+1，即其下标为i
 * 需要注意的是不能在某一次使得k变为0，比如n=14时，正确的分法为 14 = 2*3! + 0*2! + 1*1! + 1
 * 虽然更直观的分法是 2*3! + 1*2!，
 */


class Solution {
public:
    string getPermutation(int n, int k) {
    	string res = "";

        vector<int> availible;
        for (int i = 1; i <= n; ++i) {
            availible.push_back(i);
        }

        for (int i = n - 1; i > 0; --i) {
        	int total = factorial(i);
        	int factor = k / total;
        	if (k % total == 0) {
        		-- factor;
        	}
        	k -= factor * total;

        	res += (availible[factor] + '0');
        	availible.erase(availible.begin() + factor);
        }

        res += (availible[0] + '0');
        return res;
    }

    int factorial(int n) {
        int res = 1;
        while (n > 0) {
            res *= n;
            --n;
        }
        return res;
    }
};
