#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<vector<int>> graph(n);
        // Building the graph with all valid pairs
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) <= limit)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        vector<int> result = nums;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> indices, values;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    indices.push_back(node);
                    values.push_back(nums[node]);
                    for (int j = 0; j < graph[node].size(); j++)
                    {
                        if (!visited[graph[node][j]])
                        {
                            q.push(graph[node][j]);
                            visited[graph[node][j]] = true;
                        }
                    }
                }
                sort(values.begin(), values.end());
                sort(indices.begin(), indices.end());
                for (int j = 0; j < indices.size(); j++)
                {
                    result[indices[j]] = values[j];
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 60, 34, 84, 62, 56, 39, 76, 49, 38};
    int limit = 4;
    vector<int> res = s.lexicographicallySmallestArray(nums, limit);
    // expected {1, 56, 34, 84, 60, 62, 38, 76, 49, 39}
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
