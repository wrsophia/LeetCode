#include <iostream>
#include <cstdlib>
#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

//��һ�������һ����ϣ��
//ɾ����ʱ��Ϊ��ʹʱ�临�Ӷ�ΪO(1)��ɾ���������һ��Ԫ�أ���������Ԫ�طŵ���ɾ��Ԫ�ص�λ��

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


