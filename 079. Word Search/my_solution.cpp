/**
 * 有点类似走迷宫的思路
 * 看了别人的思路，还有种 space O(1) 的方法，直接改board，经过的标*，走不通了再一个个改回来(递归函数将要返回时)
 */


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        } else if (board[0].size() == 0) {
            return false;
        }
        
        vector<bool> r (board[0].size(), false);
        vector<vector<bool>> used (board.size(), r);
        
        bool found = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (findWord(board, used, i, j, word, 0)) {  // 这里这样用会省时一些
                    return true;
                }
            }
        }
        return false;
    }
    
    bool findWord(vector<vector<char>>& board, vector<vector<bool>>& used, int row, int col, string word, int idx) {
        if (idx == word.length()) {
            return true;
        } else if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return false;
        } else if (used[row][col] || board[row][col] != word[idx]) {
            return false;
        } else {
            bool found = false;
            used[row][col] = true;
            
            if (!found) {  // go up
                found = findWord(board, used, row - 1, col, word, idx + 1);
            }
            if (!found) {  // go right
                found = findWord(board, used, row, col + 1, word, idx + 1);
            }
            if (!found) {  // go down
                found = findWord(board, used, row + 1, col, word, idx + 1);
            }
            if (!found) {  // go left
                found = findWord(board, used, row, col - 1, word, idx + 1);
            }
            used[row][col] = false;
            return found;
        }
    }
};