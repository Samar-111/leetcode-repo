#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); 
        backtrack(candidates, target, 0, combination, results);
        return results;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
           
            if (i > start && candidates[i] == candidates[i-1]) continue;

            if (candidates[i] > target) break;

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, results);
            combination.pop_back(); 
        }
    }
};