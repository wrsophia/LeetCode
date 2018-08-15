/**
 * 二叉树是天然的递归模型，到了每个子节点都是和父节点相同的问题
 * 那么判断一种组合可不可能是scramble的时候，对于根节点来说就有两种情况，一种子节点没交换过，另一种交换了，对于它的子节点们来说还是相同情况
 * 于是对根节点来说，有n-1种拆分情况，每种有交换和不交换两种情况
 * 用map记录是为方便已经处理过的情况不重复处理
 */


class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> scrambleMap;
        return dfs(scrambleMap, s1, s2);
    }

    bool dfs(unordered_map<string, bool>& scrambleMap, string s1, string s2) {
        int n = s1.length();
        if (n == 0) {
            return true;
        }
        if (n == 1) {
            return s1 == s2;
        }
        if (scrambleMap.count(s1 + s2)) {
            return scrambleMap[s1 + s2];
        }

        bool res = false;
        for (int i = 1; i < n && !res; ++i) {
            res = res ||
                dfs(scrambleMap, s1.substr(0, i), s2.substr(0, i)) && dfs(scrambleMap, s1.substr(i, n - i), s2.substr(i, n - i));
            res = res ||
                dfs(scrambleMap, s1.substr(0, i), s2.substr(n - i, i)) && dfs(scrambleMap, s1.substr(i, n - i), s2.substr(0, n - i));
        }

        return scrambleMap[s1 + s2] = res;
    }
};
