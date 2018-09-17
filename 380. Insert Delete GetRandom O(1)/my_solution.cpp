/**
 * 想要random在O(1)时间，应该用一个vector，但是vector只有在末尾插入和末尾删除的时候时间是O(1)，
 * 于是要用一个map记录下标，当删除某个元素的时候，把vector中最后一个元素复制到要删除的位置，实际删除vector最后一个元素
 */


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, int> m;
    int cnt;

    RandomizedSet() {
        cnt = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        v.push_back(val);
        m[val] = cnt;   // 记录下标
        ++cnt;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        int idx = m[val];
        --cnt;
        m[v[cnt]] = idx;
        v[idx] = v[cnt];
        m.erase(val);
        v.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % cnt;
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
