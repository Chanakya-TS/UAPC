class Solution {
public:
    bool isPalindrome(string s) {
        string modified;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(isalpha(s[i]) || isdigit(s[i])) modified += tolower(s[i]);
        }
        string rev = modified;
        reverse(rev.begin(), rev.end());
        return modified == rev;
    }
};
