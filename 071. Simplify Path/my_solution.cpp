/**
 * 思路就是，从每个"/"处切开，如果是"."就跳过，如果是".."就删掉最后一个，其他情况就在末尾加上
 */


class Solution {
public:
    string simplifyPath(string path) {
        int i = 0, j = i+ 1;
        int n = path.length();
        string res = "";

        while (i < n) {
            while (j < n && path[j] != '/') {
                ++j;
            }
            if (j != i + 1) {
                string folder = path.substr(i, j - i);
                if (folder != "/.") {
                    if (folder == "/.." && res != "") {
                        res.erase(res.rfind("/"), res.length() - res.rfind("/"));
                    } else if (folder != "/..") {
                        res += folder;
                    }
                }
            }
            i = j, j = i + 1;
        }
        if (res == "") {
            return "/";
        }
        return res;
    }
};
