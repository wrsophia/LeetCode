#include <iostream>
#include <cstdlib>
#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

//用一个数组和一个哈希表
//删除的时候为了使时间复杂度为O(1)，删除的是最后一个元素，并把最后的元素放到想删的元素的位置

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (hash.count(val))
			return false;
		number.push_back(val);
		hash[val] = number.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!hash.count(val))
			return false;
		int last = number.back();
		number[hash[val]] = last;
		number.pop_back();
		hash[last] = hash[val];
		hash.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return number[rand() % number.size()];
	}
private:
	unordered_map<int, int> hash;
	vector<int> number;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/


