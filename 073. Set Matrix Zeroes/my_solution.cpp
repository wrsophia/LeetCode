/**
 * 从左上角到右下角遍历，若遇到0就把它上方和左方都填为0，但是先不能管第一行第一列
 * 如果某点不是0，看它的最左边和最上边是否为0，若是，表示这一行或这一列已被其它点标0，则把它也填为0
 * 最后再视需要把第一行第一列填0
 * 注意 viewAngel 那两个for循环不一样，要仔细再走一遍，不要投机取巧复制
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }
        int depth = min(m, n);
        
        bool left = false, up = false;   // 把第一行和第一列是否有0记录下来，最后再填
        for (int i = 0; i < m; ++i) {
        	if (matrix[i][0] == 0) {
        		left = true;
        		break;
        	}
        }
        for (int i = 0; i < n; ++i) {
        	if (matrix[0][i] == 0) {
        		up = true;
        		break;
        	}
        }

        for (int i = 1; i < depth; ++i) {
        	viewAngel(matrix, i, m, n);
        }

        if (left) {
        	for (int i = 0; i < m; ++i) {
        		matrix[i][0] = 0;
        	}
        }
        if (up) {
        	for (int i = 0; i < n; ++i) {
        		matrix[0][i] = 0;
        	}
        }
    }

    void viewAngel(vector<vector<int>>& matrix, int start, int m, int n) {
        for (int i = start; i < m; ++i) {         // 向下遍历角所在的列并进行填充
            if (matrix[i][start] == 0) {
                for (int s = i - 1; s >= 0; --s) {       // 把0上面的数字都置0
                    matrix[s][start] = 0;
                }
                for (int s = start - 1; s >= 0; --s) {      // 把0左边的数字置0
                    matrix[i][s] = 0;
                }
            } else if (matrix[i][0] == 0 || matrix[0][start] == 0) {     // 只有行列的开头是0的时候才置0，避免出现如左边一位本来是由上面数字而置0的结果把当前位也搞成0了这种情况
                matrix[i][start] = 0;
            }
        }

        for (int i = start + 1; i < n; ++i) {        // 向右遍历角所在的行，并填充
            if (matrix[start][i] == 0) {
            	for (int s = start - 1; s >= 0; --s) {       // 把0上面的数字都置0
                    matrix[s][i] = 0;
                }
                for (int s = i - 1; s >= 0; --s) {      // 把0左边的数字置0
                    matrix[start][s] = 0;
                }
            } else if (matrix[start][0] == 0 || matrix[0][i] == 0) {     // 只有行列的开头是0的时候才置0，避免出现如左边一位本来是由上面数字而置0的结果把当前位也搞成0了这种情况
                matrix[start][i] = 0;
            }
        }
    }
};
