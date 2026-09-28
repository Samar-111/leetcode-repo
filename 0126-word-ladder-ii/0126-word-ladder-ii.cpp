class Solution {
    void dfs(string word,string& beginWord, unordered_map<string,vector<string>> & parents, vector<string> & path, vector<vector<string>>& answer){
    if(word==beginWord){
        vector<string> sequence=path;
        reverse(sequence.begin(), sequence.end());
        answer.push_back(sequence);
        return;
    }
    for(string& parent: parents[word]){
        path.push_back(parent);
        dfs(parent, beginWord, parents, path, answer);
        path.pop_back();
    }
}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary(wordList.begin(),wordList.end());
        vector<vector<string>>answer;
        if(dictionary.find(endWord)== dictionary.end()){
            return answer;
        }
        unordered_map<string,vector<string>>parents;
        unordered_set<string> currentlevel;
        currentlevel.insert(beginWord);
        dictionary.erase(beginWord);
        bool found=false;
        while(!currentlevel.empty() && !found){
            unordered_set<string>nextlevel;
            for(string word: currentlevel){
                dictionary.erase(word);
            }
            for(string word: currentlevel){
                string changed=word;
                for(int pos=0;pos<(int)changed.size();pos++){
                    char original=changed[pos];
                    for(char ch='a'; ch<='z'; ch++){
                        changed[pos]=ch;
                        if(dictionary.find(changed) != dictionary.end()){
                            nextlevel.insert(changed);
                            parents[changed].push_back(word);
                            if(changed==endWord){
                                found=true;
                            }
                        }
                    }
                    changed[pos]=original;
                }
            }
            currentlevel=nextlevel;
        }
        if(!found){
            return answer;
        }
        vector<string>path={endWord};
        dfs(endWord,beginWord,parents,path,answer);
        return answer;
        
    }
};
