class Solution {
    bool dfs(int course,vector<vector<int>>& graph, vector<int>& state, vector<int> &ans){
        if(state[course]==1) return false;
        if(state[course]==2) return true;
        state[course]=1;
        for(int next: graph[course]){
            if(!dfs(next,graph,state,ans)) return false;

        }state[course]=2;
        ans.push_back(course);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto p: prerequisites){
            int course=p[0];
            int prerequisitives=p[1];
            graph[prerequisitives].push_back(course);
        }
        vector<int> state(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,graph,state,ans))
            return{};
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};