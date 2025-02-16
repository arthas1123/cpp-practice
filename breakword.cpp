#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i <= s.size(); i++)
        {
            for (const string &word : wordDict)
            {
                int start = i - word.length();
                if (start >= 0 && dp[start] && s.substr(start, word.length()) == word)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution sol;
    string str1 = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << sol.wordBreak(str1, wordDict) << endl;
    return 0;
}
