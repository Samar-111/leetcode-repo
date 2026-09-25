class Solution {
    public:
    bool dfs(int course, vector<vector<int>>& graph,vector<int>& state){
        if(state[course]==1){
            return false;
        }
        if(state[course]==2){
            return true;
        }
        state[course]=1;
        for(int next: graph[course]){
            if(!dfs(next,graph,state)){
                return false;
            }
        }
        state[course]=2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto prerequisite: prerequisites){
            int course=prerequisite[0];
            int prerequisitecourse=prerequisite[1];
            graph[prerequisitecourse].push_back(course);
        }
        vector<int>state(numCourses,0);
        for(int course=0;course<numCourses;course++){
            if(!dfs(course,graph,state)){
                return false;
            }
        }
        return true;
        
    }
};