/*
給定一組不重複的數字，返回所有可能的子集（包括空集）。
範例：
Input: [1,2,3]
Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
*/
#include <iostream>
#include <vector>

using std::vector, std::cout;

/*************  ✨ Codeium Command ⭐  *************/
/**
 * Generates all possible subsets of a given set by using backtracking.
 *
 * This function is called recursively to explore all subsets that include
 * or exclude each number in the input vector. It appends each intermediate
 * subset to the result vector.
 *
 * @param nums The input vector of unique integers.
 * @param start The starting index for generating subsets.
 * @param temp A temporary vector storing the current subset being constructed.
 * @param res A reference to the vector of vectors where each subset is stored.
 */

/******  56cec884-f486-47c5-bc39-ffcd36d7942d  *******/
void backtrack(vector<int> &nums, int start, vector<int> &temp, vector<vector<int>> &res)
{
    res.push_back(temp);
    for (int i = start; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        backtrack(nums, i + 1, temp, res);
        temp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(nums, 0, temp, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << std::endl;
    }
    return 0;
}
