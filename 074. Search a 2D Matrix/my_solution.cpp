/**
 * 其实这个题还有个更快的方法就是，在判断数字在第几行的时候也用二分法 
 */


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        for (int i = 0; i < m; ++i) {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                return binarySearch(matrix[i], target);
            }
        }

        return false;
    }

    bool binarySearch(vector<int> row, int target) {
        int left = 0;
        int right = row.size() - 1;

        while (left <= right) {
            int mid = right - (right - left) / 2;

            if (row[mid] == target) {
                return true;
            } else if (row[mid] > target) {
                right = mid - 1;
            } else {
                left = mid +1;
            }
        }
        return false;
    }
};
