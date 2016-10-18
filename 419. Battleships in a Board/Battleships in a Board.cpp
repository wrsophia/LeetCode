#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//����ÿ���㣬�������ı�Ϊ'.'�����ڲ����޸���������������¿�һ������
//˼·�� 200.Number of Ilands (dfs) ����

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