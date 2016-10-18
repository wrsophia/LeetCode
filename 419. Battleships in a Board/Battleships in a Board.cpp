#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//遍历每个点，遍历到的变为'.'，由于不能修改输入参数，于是新开一个数组
//思路和 200.Number of Ilands (dfs) 类似

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		vector<vector<char>> tmp = board;
		int n1 = board.size(), n2 = board[0].size();
		int cnt = 0;
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < n2; ++j) {
				if (tmp[i][j] == 'X') {
					tmp[i][j] = '.';
					++cnt;
					int a = i, b = j;
					while (a + 1 < n1 && tmp[a + 1][b] == 'X') {
						++a;
						tmp[a][b] = '.';
					}
					while (b + 1 < n2 && tmp[a][b + 1] == 'X') {
						++b;
						tmp[a][b] = '.';
					}
				}
			}
		}
		return cnt;
	}
};