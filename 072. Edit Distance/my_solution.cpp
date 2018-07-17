/*
 * 为方便理解，可以理解为修改后两个字符串其实是相同的，只不过是记下了步数
 * 想要知道 dis[i][j] 是多少，有三种情况
 * 一种是把w1[0...i-2]和w2[0...j-2]改到相等，然后看w1[i-1]是否等于w2[j-1]，即 dis[i - 1][j - 1] + (word1[i - 1] != word2[j - 1])
 * 一种是把去掉w2[j-1]，然后把w1[0...i-1]和w2[0...j-2]改到相等，即 dis[i][j - 1] + 1
 * 一种是把w1[i-1]去掉，然后把w1[0...i-2]和w2[0...j-1]改到相等，即 dis[i - 1][j] + 1
 * 但是这还没有结束，还涉及到初值怎么赋
 * 注意到，dis[i][j]是w1[0...i-1]和w2[0...j-1]的距离，于是dis[i][0]就是w1[0...i-1]和""的距离，即w1[0...i-1]=i
 * dis[0][j]就是w2[0...j-1]和""的距离，即dis[0][j]=j
 */


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> disCol (n + 1, 0);
        vector<vector<int>> dis (m + 1, disCol);

        for (int i = 1; i <= m; ++i) {
            dis[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dis[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = triMin(dis[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]),
                               dis[i][j - 1] + 1, dis[i - 1][j] + 1);
            }
        }
        return dis[m][n];
    }

    int triMin(int a, int b, int c) {
        int d = a < b ? a : b;
        return (c < d) ? c : d;
    }
};
