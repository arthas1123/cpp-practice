#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    /**
     * Return a vector of the lexicographic order of the numbers from 1 to n.
     *
     * @param n The upper limit of the numbers to generate.
     *
     * @return A vector of the lexicographic order of the numbers from 1 to n.
     */
    {
        vector<int> ans;
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(num);
            if (num * 10 <= n)
            {
                num *= 10;
            }
            else
            {
                if (num >= n)
                {
                    num /= 10;
                }
                num += 1;
                while (num % 10 == 0)
                {
                    num /= 10;
                }
            }
        }
        return ans;
    }
};

/**
 * The main function is an example of how to use the Solution class to find the
 * lexicographic order of a given number.
 *
 * @return 0
 */
int main()
{
    Solution s;
    vector<int> ans = s.lexicalOrder(13);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
