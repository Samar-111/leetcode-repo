class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, vis, pathVis, adj))
                    return true;
            }
            else if (pathVis[adjacentNode]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        // Build adjacency list
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj))
                    return false;   
            }
        }

        return true;    
    }
};