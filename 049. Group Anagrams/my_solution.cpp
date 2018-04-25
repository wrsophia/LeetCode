#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
一种方法就是对每个字符串按字母顺序排序，另一种方法就是，这个很像分解质因数，一个数字的质因数分解只能有一种情况，
于是我们可以令26个字母每个对因一个质数，用乘积作为map的key。
关于map的value是什么，有两种思路，比较直观的就是该product下的vector<string>，但是这样就得在最后再来一个循环，
遍历key，把各个vector<string>添加到res里。另一种思路，可以让product对应该vector在res里的下标，于是定义一个
变量，记录idx到了哪里，每当遇到一个新的product，idx++，即在res里放入一个新数组。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	int prime_arr[] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37, 41, 43, 47, 53, 
    		59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    	vector<int> primes (prime_arr, prime_arr + sizeof(prime_arr) / sizeof(int));

    	unordered_map<int, int> divide;
        vector<vector<string> > res;
    	
        int idx = 0;
    	for (string str : strs) {
    		int product = 1;
    		for (int i = 0; i < str.size(); ++i) {
    			product *= primes[str[i] - 'a'];
    		}
 
    		if (divide.find(product) != divide.end()) {
    			res[divide[product]].push_back(str);
    		} else {
    			divide[product] = idx++;
                vector<string> temp;
                temp.push_back(str);
                res.push_back(temp);
    		}
    	}

        return res;
    }
};