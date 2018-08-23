/**
 * 比较直观能看出来是dfs，但遍历的时候又可以很大的简化，比如说一个start只用考察三位，后面剩的太多或太少了可以提前结束本次递归
 */


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip = "";
        dfs(s, 0, 0, ip, res);
        return res;
    }

    void dfs(string s, int start, int step, string ip, vector<string>& res) {
        if (start == s.length() && step == 4) {
            res.push_back(ip.substr(0, ip.length() - 1));   // 去掉末尾的'.'
            return;
        }
        if (s.length() - start > 3 * (4 - step)) {
            return;
        }
        if (s.length() - start < (4 - step)) {
            return;
        }

        int num = 0;
        for (int i = start; i < start + 3; ++i) {
            num = 10 * num + (s[i] - '0');
            if (num <= 255) {
                dfs(s, i + 1, step + 1, ip + s.substr(start, i - start + 1) + '.', res);
            }
            if (num == 0) {    // 判断放在这里阻止了0开头的2、3位数，却保留了0
                break;
            }
        }
    }
};
