class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int playerIndex=0;
        int trainerIndex=0;
        while(playerIndex<players.size() && trainerIndex<trainers.size()){
            if(trainers[trainerIndex]>=players[playerIndex]){
                playerIndex++;
            }
            trainerIndex++;
        }
        return playerIndex;
    }
};