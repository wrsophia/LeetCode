#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;



class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, mid = INT_MAX;  
        for(int val: nums)  
        {  
            if(val <= small) small = val;  
            else if(val <= mid) mid = val;  
            else return true;  
        }  
        return false;  
    }
};

int main()
{
	int arr[] = {1,2,-10,-8,-7};
	vector<int> nums(arr, arr + 5);
	cout << boolalpha << increasingTriplet(nums) << endl;
	system("pause");
	return 0;
}