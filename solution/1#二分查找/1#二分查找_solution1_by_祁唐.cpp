#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
int binary_s(vector<int> &nums, int pl, int pr, int target)
{
    if (pl + 1 >= pr)
    {
        if (target == nums[pr])
            return pr;
        if (target == nums[pl])
            return pl;
        return -1;
    }
    int pm = (pr + pl) / 2; // 0 10 --> 5(中间); 3 8 -->5(中间偏左)
    //cout<<pl<<" "<<pr<<" " <<pm<<endl;
    if (target == nums[pm])
        return pm;
    if (target > nums[pm]) // 在mid右边
    {
        return binary_s(nums, pm, pr, target);
    }
    else
        return binary_s(nums, pl, pm, target);
}
    int search(vector<int> &nums, int target)
    {
        return binary_s(nums, 0, nums.size() - 1, target);
    }
};