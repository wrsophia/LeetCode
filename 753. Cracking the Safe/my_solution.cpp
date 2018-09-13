/**
 * 这个也没啥办法，就穷举吧，于是dfs最合适
 * 但是注意一点，这个dfs加上了返回值，如果找到了，就从所有函数的28行返回了，后面就不再执行了，
 * 省时是一方面，更重要的是防止ans一点一点pop_back, 返回到最上一层就空了
 */


class Solution {
public:
    string crackSafe(int n, int k) {
        string ans(n, '0');
        unordered_set<string> pwd;
        pwd.insert(ans);
        dfs(n, k, ans, pwd);
        return ans;
    }

    bool dfs(const int n, const int k, string& ans, unordered_set<string>& pwd) {
        if (pwd.size() == pow(k, n)) {
            return true;
        }
        for (int i = 0; i < k; ++i) {
            ans += '0' + i;
            string curr = ans.substr(ans.length() - n);
            if (pwd.find(curr) == pwd.end()) {
                pwd.insert(curr);
                if (dfs(n, k, ans, pwd)) {
                    return true;
                }
                pwd.erase(curr);
            }
            ans.pop_back();
        }
        return false;
    }
};

