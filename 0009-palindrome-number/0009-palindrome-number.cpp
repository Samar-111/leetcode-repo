class Solution {
public:
    bool isPalindrome(int x) {
        int revnum=0;
        int dp=x;
        while(x>0){
            int lastdigit=x%10;
            if (revnum > INT_MAX / 10 || (revnum == INT_MAX / 10 && lastdigit > 7))
                return 0;
            if (revnum < INT_MIN / 10 || (revnum == INT_MIN / 10 && lastdigit < -8))
                return 0;

            revnum=(revnum*10)+lastdigit;
            x=x/10;

        }
        if(dp==revnum) {
            return true;
        }
        else {
            return false;
        }
        
    }
};