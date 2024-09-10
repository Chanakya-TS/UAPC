class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod = 1000000007;
        vector<vector<long long>> dp(n, vector<long long>(5));
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                if(i == 0) dp[i][j] = 1;
                else {
                    if(j == 0){
                        dp[i][j] = dp[i-1][1];
                    } else if(j == 1){
                        dp[i][j] = (dp[i-1][0] + dp[i-1][2]) % mod;
                    } else if(j == 2){
                        dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % mod;
                    } else if(j == 3){
                        dp[i][j] = (dp[i-1][2] + dp[i-1][4]) % mod;
                    } else {
                        dp[i][j] = dp[i-1][0];
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<5; i++) ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
};
