#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // failed when handling negative numbers
    int shortestSubarray(vector<int> &nums, int k)
    {
        int subSum = nums[0];
        int left = 0;
        int right = 1;
        int res = INT_MAX;
        if (subSum >= k)
            return 1;
        for (right; right < nums.size(); right++)
        {
            subSum += nums[right];
            if (subSum >= k)
            {
                res = min(res, right - left + 1);
            }
            while (right > left)
            {
                subSum -= nums[left];
                left++;
                if (subSum >= k)
                {
                    res = min(res, right - left + 1);
                }
                if (res == 1)
                {
                    return 1;
                }
                continue;
            }
        }
        if ((right == left) || res > nums.size())
            return -1;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {8};
    int k = 8;
    cout << s.shortestSubarray(nums, k) << endl;
    return 0;
}
