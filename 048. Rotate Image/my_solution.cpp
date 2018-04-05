#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
一圈一圈的变换，每次四个元素互换，假设位置(注意是位置，不是元素)按顺时针方向为a, b, c, d
先互换位置a, b，再互换a, c, 最后互换a, d，即可完成4个元素的顺时针旋转
对一行的每个元素作为位置a所组成的正方形都做此swap，就完成了整个圈的顺时针旋转
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0, end = matrix.size() - 1;
        
        while (start < end) {
            rotate_square(matrix, start++, end--);
        }  
    }
    
    void rotate_square(vector<vector<int>>& matrix, int start, int end) {
        for (int i = 0; i < end - start; ++i) {
            swap(matrix[start][start + i], matrix[start + i][end]);
            swap(matrix[start][start + i], matrix[end][end - i]);
            swap(matrix[start][start + i], matrix[end - i][start]);
        }
    }
};