class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for(char c : s) {
            if (isalnum(c)) {
                x += tolower(c);
            }
        }

        int l = 0 , r = x.size()-1;
        while(l<r) {
            if(x[l] != x[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
};