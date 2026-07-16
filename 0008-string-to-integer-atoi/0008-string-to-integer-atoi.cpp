class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long ans = 0;
        bool isneg = false;

        while(i < n && s[i] == ' '){
            i++;
        }
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
                isneg = true;
            }
            i++;
        }
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if(isneg == false && ans > INT_MAX){
                return INT_MAX;
            }
            if(isneg == true && -ans < INT_MIN){
                return INT_MIN;
            }
            i++;
        }

        return (isneg == true) ? -ans : ans;
    }
};