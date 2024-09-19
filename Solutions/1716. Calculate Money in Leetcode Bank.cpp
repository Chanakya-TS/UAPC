class Solution {
public:
    int totalMoney(int n) {
        int prevMonday = 0;
        int cur = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i%7 == 0){
                // Monday
                cur = prevMonday + 1;
                prevMonday = cur;
            } else {
                cur += 1;
            }
            ans += cur;
            // cout << i << ' ' << cur << ' ' << prevMonday;
        }
        return ans;
    }
};
