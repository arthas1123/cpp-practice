#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++)
        {
            int ast = asteroids[i];
            while (!st.empty() && st.top() > 0 && ast < 0)
            {
                int top = st.top();
                if (abs(top) > abs(ast))
                {
                    ast = 0;
                }
                else if (abs(top) < abs(ast))
                {
                    st.pop();
                }
                else
                {
                    st.pop();
                    ast = 0;
                }
            }
            if (ast != 0)
                st.push(ast);
        }
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> asteroids = {5, 10, -5};
    vector<int> res = s.asteroidCollision(asteroids);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
