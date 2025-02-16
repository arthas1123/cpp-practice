#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Depth-First Search to determine if a node is eventually safe
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &state)
    {
        // If the node is already visited, return whether it is safe
        if (state[node] != 0)
            return state[node] == 2;

        // Mark the node as visiting
        state[node] = 1;

        // Visit all the adjacent nodes
        for (int next : graph[node])
        {
            // If the adjacent node is safe, continue
            if (state[next] == 2)
                continue;
            // If the adjacent node is visited or not safe, return false
            if (state[next] == 1 || !dfs(next, graph, state))
                return false;
        }

        // Mark the node as safe
        state[node] = 2;
        return true;
    }

    // Function to find all eventual safe nodes
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> state(n, 0); // 0 = unvisited, 1 = visiting, 2 = safe
        vector<int> res;

        // Check each node if it is eventually safe
        for (int i = 0; i < n; i++)
        {
            if (dfs(i, graph, state))
                res.push_back(i);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> res = s.eventualSafeNodes(graph);

    // Print the result
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
