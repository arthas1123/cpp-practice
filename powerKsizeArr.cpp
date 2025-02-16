#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*************  ✨ Codeium Command ⭐  *************/
    /**
     * Check if the given vector of integers is in ascending order
     *
     * \param nums The vector of integers
     * \return true if the vector is in ascending order, false otherwise
     */
    /******  1c5a05ba-7f95-4ba1-8ba6-983ffcc0e765  *******/
    bool checkAscend(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        vector<int> res = {};
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            vector<int> temp = {};
            for (int j = i; j < i + k; j++)
            {
                temp.push_back(nums[j]);
            }
            if (checkAscend(temp))
                res.push_back(temp.back());
            else
                res.push_back(-1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 4};
    vector<int> res = s.resultsArray(nums, 2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
