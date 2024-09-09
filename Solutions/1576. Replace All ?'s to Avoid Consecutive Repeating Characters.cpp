class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                // Check all possible values
                for(int j=0; j<26; j++){
                    char pos = 'a' + j;
                    // check if pos is a valid solution
                    if(i && s[i-1] == pos) continue;
                    if(i+1 < n && s[i+1] == pos) continue;
                    // Valid solution
                    s[i] = pos;
                    break;
                }
            }
        }
        return s;
    }
};
