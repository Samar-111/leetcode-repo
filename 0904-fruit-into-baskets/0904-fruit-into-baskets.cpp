class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=0;
        int lastfruit=-1,secondlast=-1;
        int currcount=0,lastfruitstreak=0;
        for(int fruit: fruits){
            if(fruit==lastfruit || fruit==secondlast){
                currcount++;
            }
            else{
                currcount=lastfruitstreak+1;
            }
            if(fruit==lastfruit){
                lastfruitstreak++;
            }
            else{
                lastfruitstreak=1;
                secondlast=lastfruit;
                lastfruit=fruit;
            }
            maxlen=max(maxlen,currcount);
        }
        return maxlen;
    }
};