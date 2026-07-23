class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                hash[s[j]]=1;
               
            
             int len=j-i+1;
            maxlen=max(maxlen,len);
            }

        }
        return maxlen;
        
    }
};