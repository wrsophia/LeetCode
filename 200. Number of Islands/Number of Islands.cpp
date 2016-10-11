#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == '1') {
					++count;
					dfs(grid, i, j);
				}
			}
		}
		return count;
	}
	void dfs(vector<vector<char>>& grid, int x, int y) {
		grid[x][y] = '0';
		if (x + 1 < grid.size() && grid[x + 1][y] == '1')
			dfs(grid, x + 1, y);
		if (x - 1 >= 0 && grid[x - 1][y] == '1')
			dfs(grid, x - 1, y);
		if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
			dfs(grid, x, y + 1);
		if (y - 1 >= 0 && grid[x][y - 1] == '1')
			dfs(grid, x, y - 1);
	}
	void dfs2(vector<vector<char>>& grid, int x, int y) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0')
			return;
		static int dx[] = { 1, -1, 0, 0 };
		static int dy[] = { 0, 0, 1, -1 };
		grid[x][y] = '0';
		for (int i = 0; i < 4; ++i) {
			dfs(grid, x + dx[i], y + dy[i]);
		}
	}
};