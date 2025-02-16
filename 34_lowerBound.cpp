#include <vector>

using std::vector;

class Solution
{
public:
    int lowerBound(const vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }

    vector<int> searchRange(const vector<int> &nums, int target)
    {
        int start = lowerBound(nums, target);
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        int end = lowerBound(nums, target + 1) - 1;
        return {start, end};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = s.searchRange(nums, target);
    return 0;
}
