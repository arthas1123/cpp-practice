#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int curr = 0;
        int ans = nums.size();
        for (int r = 0; r < nums.size(); r++)
        {
            curr += nums[r];
            while (curr >= target)
            {
                ans = min(ans, r - left + 1);
                curr -= nums[left];
                left++;
                        }
            if ((r == nums.size() - 1) && curr < target)
                return 0;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;
}
