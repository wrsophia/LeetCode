/**
 * 很典型的动态规划，如果某一点是1，那么它右边和下面都不能走了，于是可以把这个点的path标为0
 * 为了不给第一行和第一列赋初始值，可以在上面和左边加一圈，值为0
 */


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> temp (n + 1, 0);
        vector<vector<int>> paths (m + 1, temp);

        paths[1][1] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                if (obstacleGrid[i - 1][j - 1] == 0) {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
                
            }
        }

        return paths[m][n];
    }
};
