/**
 * 首先想到的肯定是得用一个数组把各个组合存起来，这样才能方便开头和结尾的取出
 * 组成的结果还是要放到一个数组里方便下一次取用，但是考虑到原始数组的数据取了一次之后就没有用了，
 * 所以可以把空间复用起来，再写回到原来的位置
 */


class Solution {
public:
    string findContestMatch(int n) {
        vector<string> team (n);
        for (int i = 0; i < n; ++i) {
            team[i] = to_string(i + 1);
        }
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                team[i] = '(' + team[i] + ',' + team[n - i - 1] + ')';
            }
            n /= 2;
        }
        return team[0];
    }
};
