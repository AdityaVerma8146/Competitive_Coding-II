class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = (int)s.size() - 1;
        
        while (l < r) {
            // Move left pointer if not alphanumeric, ensuring it doesn't cross r
            while (l < r && !isalnum(static_cast<unsigned char>(s[l]))) {
                l++;
            }
            // Move right pointer if not alphanumeric, ensuring it doesn't cross l
            while (l < r && !isalnum(static_cast<unsigned char>(s[r]))) {
                r--;
            }
            
            // Compare characters case-insensitively
            if (tolower(static_cast<unsigned char>(s[l])) != tolower(static_cast<unsigned char>(s[r]))) {
                return false;
            }
            
            l++;
            r--;
        }
        return true;
    }
};